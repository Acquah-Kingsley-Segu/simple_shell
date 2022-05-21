#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * execute_command - execute found command
 * @cmd: command
 * @av: arguments to command
 * @env: environment
 * Return: array of paths
 */
int execute_command(char *cmd, char **av, char **env)
{

	int wait_status;
	pid_t child_proc;
	char *command1;
	char *command2;
	char *token;

	token = malloc(sizeof(char) * 1024);
	token = strtok(cmd, "/");
	while (token != NULL)
	{
		command1 = token;
		token = strtok(NULL, "/");
	}
	command2 = find_command(command1, env);
	if (command2 != NULL)
	{
		if (strcmp(command2, "exit") == 0)
			return (EXIT_QUIT);
		child_proc = fork();
		if (child_proc == 0)
		{
			if (execve(command2, av, env) == -1)
			{
				perror("Error executing");
				return (EXIT_FAILURE);
			}
		}
		else
			wait(&wait_status);
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
