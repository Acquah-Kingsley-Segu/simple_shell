#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/usr/bin/ls"};
	char *envp[] = {NULL};
	if (execve(argv[0], argv, envp) == -1)
	{
		perror("Error");
	}

	return (0);
}
