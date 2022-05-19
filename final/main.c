#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

int main(void)
{
	extern char **environ;
	char *line;
	size_t bufsize = 1024, line_len = 0;
	char *PROMT_STR;
	ssize_t nread;
	int PROMPT_LEN;
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
			line_len = 0;
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
			break;
		}
	}
	free(ag);
	return (exit_status);
}