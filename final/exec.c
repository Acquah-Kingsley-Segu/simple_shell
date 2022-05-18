#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "shell.h"

int execute_command(char *cmd, char **av, char **env)
{

	char *command;
	command = find_command(cmd, env);
	if (command != NULL)
	{
		if (execve(command, av, env) == -1)
		{
			perror("Error");
			return (EXIT_FAILURE);
		}
		else
		{
			return (EXIT_SUCCESS);
		}
	}
}