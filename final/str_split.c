#include <string.h>
#include <stdlib.h>
#include "shell.h"

char **str_split(char *str, char const *delim)
{
	char **str_arr;
	char *token;
	int i;
	str_arr = malloc(sizeof(char *) * 1024);
	token = malloc(sizeof(char) * 1024);
	token = strtok(str, delim);
	i = 0;
	while (token != NULL)
	{
		str_arr[i] = token;
		token = strtok(NULL, delim);
		i += 1;
	}
	str_arr[i] = NULL;
	return str_arr;
}