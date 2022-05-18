#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

ssize_t nread;
ssize_t shell_prompt(char *line, size_t line_len, FILE *stream)
{
	char *PROMT_STR = "$ ";
	int PROMPT_LEN = 2;
	/* display prompt */
	write(STDOUT_FILENO, PROMT_STR, PROMPT_LEN);

	/* read command */
	nread = getline(&line, &line_len, stream);
	return nread;
}