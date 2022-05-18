#include <stdio.h>
#include <string.h>
#include "shell.h"

char **find_paths(char *env[])
{
	char *token;
	char env_var[1024 * 1024];
	char **paths;
	int i = 0;
	while (env[i] != NULL)
	{
		strcpy(env_var, env[i]);
		token = strtok(env_var, "=");
		if (strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			paths = str_split(token, ":");
			break;
		}
		i += 1;
	}
	return paths;
}