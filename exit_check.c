#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int exit_check(char *buffer, ssize_t buf_size)
{
	int i, stat = 1;
	char *_exit = "exit";
	int char_left;

	for (i = 0; i < 4; i++)
	{
		if (buffer[i] != _exit[i])
			stat = 0;
	}
	if (stat)
	{
		char_left = buf_size - 6;
		
	}
	return stat;
}
