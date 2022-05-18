#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int i, status;
	pid_t my_child, father = getpid();
	char *argv[] = {"/usr/bin/ls", "-l", "/tmp", NULL};
	char *envp[] = {NULL};
	printf("\nPARENT PID: %d\n", father);
	for (i = 0; i < 5; i++)
	{
		my_child = fork();
		if (my_child == 0)
		{
			printf("\nCHILD PID: %d\n", getpid());
			printf("\nFATHER PID: %d\n", getppid());
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("Error");
			}
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
