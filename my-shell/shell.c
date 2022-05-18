#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **split_str(char *);

int main()
{
	char *PROMT_STR = "$ ";
	int PROMPT_LEN = 2;
	size_t line_len = 0;
	ssize_t nread;
	char *line = NULL;
	int wait_status;
	pid_t child_proc;
	char **argv;
	char *envp[] = {NULL};
	while (1)
	{
		write(STDOUT_FILENO, PROMT_STR, PROMPT_LEN);
		nread = getline(&line, &line_len, stdin);
		if (nread != -1)
		{
			line_len = 0;
			child_proc = fork();
			if (child_proc == 0)
			{
				argv = split_str(line);
				if (argv[0] == NULL)
				{
					write(STDOUT_FILENO, "\r", 1);
					continue;
				}

				if (execve(argv[0], argv, envp) == -1)
				{
					perror("Error");
				}
			}
			else
			{
				wait(&wait_status);
			}
		}
		else
		{
			free(argv);
			break;
		}
	}

	exit(EXIT_SUCCESS);
}

char **split_str(char *str)
{
	char **str_arr;
	str_arr = malloc(sizeof(char *) * 1024);
	char *token;
	int i;
	token = strtok(str, " \t\n\r");
	i = 0;
	while (token != NULL)
	{
		str_arr[i] = token;
		i += 1;
		token = strtok(NULL, " ");
	}
	free(str_arr);
	return str_arr;
}