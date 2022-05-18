#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

int main(void)
{
	extern char **environ;
	char *line;
	size_t bufsize = 1024, line_len = 0;
	char *PROMT_STR;
	ssize_t nread;
	int wait_status;
	int PROMPT_LEN;
	pid_t child_proc;
	char **ag;
	int exit_status;
	line = (char *)malloc(bufsize * sizeof(char));

	PROMT_STR = "$ ";
	PROMPT_LEN = 2;
	/* display prompt */
	while (1)
	{
		write(STDOUT_FILENO, PROMT_STR, PROMPT_LEN);
		nread = getline(&line, &line_len, stdin);
		if (nread != -1)
		{
			/*prompt reset len to 0 for next iteration*/
			line_len = 0;

			/* create child process to handle command */
			child_proc = fork();
			if (child_proc == 0)
			{
				ag = str_split(line, " \t\n\r");
				if (ag[0] == NULL)
				{
					write(STDOUT_FILENO, "\r", 1);
					continue;
				}

				exit_status = execute_command(ag[0], ag, environ);
			}
			else
			{
				/* wait for child process to handle command */
				wait(&wait_status);
			}
		}
		else
		{
			free(ag);
			break;
		}
	}
	return (exit_status);
}