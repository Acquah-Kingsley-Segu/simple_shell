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
	full_command = malloc(sizeof(char) * 1024);
	int i, l;
	char **dirctories;
	char *dir;

	struct stat statbuf;
	DIR *dp;
	struct dirent *entry;
	int command_not_found = 1;
	dirctories = find_paths(envp);
	i = 0;
	dir = dirctories[i];
	while (dir != NULL && command_not_found)
	{
		l = strlen(dir);
		if ((dp = opendir(dir)) == NULL)
		{
			write(STDERR_FILENO, "Error: not found\n\0", 18);
		}
		while ((entry = readdir(dp)) != NULL)
		{
			stat(entry->d_name, &statbuf);
			if (statbuf.st_mode == S_IFDIR)
			{
				continue;
			}
			else if (strcmp(entry->d_name, cmd) == 0)
			{
				command_not_found = 0;
				strcat(full_command, dir);
				strcat(full_command, "/\0");
				strcat(full_command, entry->d_name);
				printf("full command; %s\n", full_command);
				break;
			}
		}
		i += 1;
		dir = dirctories[i];
		closedir(dp);
	}
	return full_command;
}
