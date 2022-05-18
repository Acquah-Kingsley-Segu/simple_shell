#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char const *argv[], char const *envp[])
{
	size_t i;
	char *token;
	char *directories;
	char env_var[1024 * 1024];
	DIR *dp;
	char command[] = "echo";
	struct dirent *entry;
	struct stat statbuf;
	int command_not_found = 1;
	i = 0;
	while (envp[i] != NULL)
	{

		strcpy(env_var, envp[i]);
		token = strtok(env_var, "=");
		if (strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			directories = token;
			token = strtok(directories, ":");
			while (token != NULL && command_not_found)
			{
				printf("path; %s\n", token);
				if ((dp = opendir(token)) == NULL)
				{
					write(STDERR_FILENO, "Error: not found\n\0", 18);
					return (EXIT_FAILURE);
				}
				while ((entry = readdir(dp)) != NULL)
				{
					stat(entry->d_name, &statbuf);
					if (S_ISDIR(statbuf.st_mode))
					{
						continue;
					}
					if (strcmp(entry->d_name, command) == 0)
					{
						printf("Found %s at %s/\n", entry->d_name, token);
						command_not_found = 0;
						break;
					}
				}
				closedir(dp);
				token = strtok(NULL, ":");
			}
		}
		i += 1;
	}
	return (0);
}
