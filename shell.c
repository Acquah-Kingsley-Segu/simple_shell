#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * main - starting point for shell
 *
 * Return: 0
 */

int main(void)
{

	size_t line_len = 0;
	ssize_t nread;
	char *line = NULL;

	while (1)
	{
		int exit_status;

		line = shell_prompt(line, line_len, &nread);
		exit_status = exit_check(line, nread);
		if (exit_status)
			exit(exit_status);

		command_exec(line, nread);
		line_len = 0;
	}

	exit(EXIT_SUCCESS);
}
