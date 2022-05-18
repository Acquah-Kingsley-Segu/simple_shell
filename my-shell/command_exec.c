#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * command_exec - creates a process that executes the command entered
 * @line: pointer to command entered
 * @nread: number of characters read
 *
 */

void command_exec(char *line, ssize_t nread)
{
	int wait_status;
	pid_t child_proc;
	char **argv = NULL;
	char *envp[] = {NULL};

	if (nread != -1)
	{
		child_proc = fork();
		if (child_proc == 0)
		{
			argv = split_str(line);
			if (argv[0] == NULL)
			{
				write(STDOUT_FILENO, "\r", 1);
			}
			if (execve(argv[0], argv, envp) == -1)
			{
				write(STDOUT_FILENO, "./shell: No such file or directory\n", 35);
			}
		}
		else
		{
			wait(&wait_status);
		}
	}
	else
	{
		free(argv);
	}
}
