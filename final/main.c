#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "shell.h"

int main(void)
{
	extern char **environ;
	char *line = NULL;
	char *PROMT_STR;
	ssize_t nread;
	int PROMPT_LEN;
	char **ag;
	char *first_ag;
	int exit_status;

	size_t line_len = 0;
	PROMT_STR = "$ ";
	PROMPT_LEN = 2;
	exit_status = 0;

	/* display prompt */
	for (;;)

	{
		/* Handle ^C (Ctrl + C)*/
		signal(SIGINT, SIG_IGN);
		/* Prevent zombie children */
		signal(SIGCHLD, SIG_IGN);
		write(STDOUT_FILENO, PROMT_STR, PROMPT_LEN);
		nread = getline(&line, &line_len, stdin);

		if (nread != -1)
		{
			line_len = 0;
			ag = str_split(line, " \r\n\a\t");
			first_ag = ag[0];
			if (first_ag != NULL)
			{
				exit_status = execute_command(first_ag, ag, environ);
				if (exit_status == EXIT_QUIT)
				{
					exit(EXIT_SUCCESS);
				}
			}
		}
		free(line);
	}
	free(ag);
	return (exit_status);
}