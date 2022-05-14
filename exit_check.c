#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int exit_check(char *buffer, ssize_t buf_size)
{
	int i, stat = 1;
	char *_exit = "exit";
	int expo, num, status = 0, mul = 1;

	for (i = 0; i < 4; i++)
	{
		if (buffer[i] != _exit[i])
			stat = 0;
	}
	if (stat && buf_size > 5)
	{
		expo = buf_size - 7;
		i = 5;
		for (; i < buf_size - 1; i++)
		{
			num = buffer[i] - 48;
			expo = buf_size - i - 2;
			for (; expo > 0; expo--)
			{
				mul *= 10;
				num *= mul;
			}
			status += num;
		}

		return status;
	}
	return stat;
}
