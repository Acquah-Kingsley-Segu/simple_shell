#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "shell.h"

/**
 * find_command - find a command
 * @cmd: count of arguments
 * @envp: string array of environment variables
 * Return: string representing the full command path
 * or NULL if it doesn't exits
 */
char *find_command(char *cmd, char **envp)
{
	char *full_command;
	char **dirctories;
	DIR *dp;
	struct dirent *entry;
	int i = 0, command_not_found = 1;

	full_command = malloc(sizeof(char) * 1024);
	if (strcmp(cmd, "exit") == 0)
	{
		full_command = cmd;
		return (full_command);
	}
	dirctories = find_paths(envp);
	while (dirctories[i] != NULL && command_not_found)
	{
		dp = opendir(dirctories[i]);
		if (dp == NULL)
		{
			i += 1;
			continue;
		}
		while ((entry = readdir(dp)) != NULL)
		{
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue;
			if ((strcmp(entry->d_name, cmd) == 0))
			{
				command_not_found = 0;
				strcpy(full_command, dirctories[i]);
				strcat(full_command, "/\0");
				strcat(full_command, entry->d_name);
				break;
			}
		}
		i += 1;
		closedir(dp);
	}
	return (full_command);
}
