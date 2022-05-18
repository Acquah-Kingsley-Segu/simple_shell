#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * shell_prompt - creates the prompt of the shell and receives input
 * @line: buffer to write command into
 * @line_len: length of command to receive
 * @nread: number of characters entered from stdin
 *
 * Return: buffer to command collected
 */

char *shell_prompt(char *line, size_t line_len, ssize_t *nread)
{
	char *PROMT_STR = "$ ";
	int PROMPT_LEN = 2;

	write(STDOUT_FILENO, PROMT_STR, PROMPT_LEN);
	*nread = getline(&line, &line_len, stdin);

	if (*nread == EOF || *nread == -1)
	{
		write(STDOUT_FILENO, "\n", PROMPT_LEN - 1);
		exit(EXIT_FAILURE);
	}

	return (line);
}


