#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char* shell_prompt(char *buffer, size_t buf_size, ssize_t *characters)
{
	size_t write_stat;
	char *_exit = "exit";
	int stat;
	int i = 0;

	write_stat = write(0, "#cisfun$ ", 9);
	if (write_stat == -1)
		exit(EXIT_FAILURE);

	*characters = getline(&buffer, &buf_size, stdin);
	if (*characters == -1)
	{
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	stat = exit_check(buffer, *characters);
	if (stat)
		exit(stat);

	return buffer;
}
