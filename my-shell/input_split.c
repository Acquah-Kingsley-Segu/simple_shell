#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * split_str - splits the command entered into parts of command syntax
 * @str: command entered
 *
 * Return: a pointer to a pointer
 */

char **split_str(char *str)
{
	char **str_arr;
	char *token;
	int i;

	str_arr = malloc(sizeof(char *) * 1024);
	token = strtok(str, " \t\n\r");
	i = 0;
	while (token != NULL)
	{
		str_arr[i] = token;
		i += 1;
		token = strtok(NULL, " ");
	}
	return (str_arr);
}
