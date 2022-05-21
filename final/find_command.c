#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "shell.h"

char *find_command(char *cmd, char **envp)
{
	char *full_command;
	int i, command_not_found;
	char **dirctories;
	struct stat statbuf;
	DIR *dp;
	struct dirent *entry;
	full_command = malloc(sizeof(char) * 1024);

	if (strcmp(cmd, "exit") == 0)
	{
		full_command = cmd;
		return (full_command);
	}

	command_not_found = 1;
	dirctories = find_paths(envp);
	i = 0;
	while (dirctories[i] != NULL && command_not_found)
	{
		if ((dp = opendir(dirctories[i])) == NULL)
		{
			i += 1;
			continue;
			;
		}
		while ((entry = readdir(dp)) != NULL)
		{
			stat(entry->d_name, &statbuf);
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			{
				continue;
			}

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
