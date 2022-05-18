#include <string.h>
#include <stdlib.h>
#include "shell.h"

char **str_split(char *str, char const *delim)
{
	char **str_arr;
	str_arr = malloc(sizeof(char *) * 1024);
	char *token;
	int i;
	token = strtok(str, delim);
	i = 0;
	while (token != NULL)
	{
		str_arr[i] = token;
		token = strtok(NULL, delim);
		i += 1;
	}
	return str_arr;
}