#include <string.h>
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
	size_t i, l;
	char **dirctories;
	char *dir;
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	int command_not_found = 1;
	i = 0;
	dirctories = find_paths(envp);
	while (dirctories[i] != NULL && command_not_found)
	{
		dir = dirctories[i];
		l = strlen(dir);
		printf("PATH %s len; %zu\n", dir, l);
		if ((dp = opendir(dir)) == NULL)
		{
			write(STDERR_FILENO, "Error: not found\n\0", 18);
		}
		while ((entry = readdir(dp)) != NULL)
		{
			stat(entry->d_name, &statbuf);
			if (S_ISDIR(statbuf.st_mode))
			{
				continue;
			}
			else if (strcmp(entry->d_name, cmd) == 0)
			{

				command_not_found = 0;
				strcat(full_command, dirctories[i]);
				strcat(full_command, cmd);
				break;
			}
		}
		closedir(dp);
		i += 1;
	}
	return full_command;
}
