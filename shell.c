#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	ssize_t write_stat, exec_stat;
	char *buffer = NULL;
	size_t buf_size = 0;
	ssize_t characters;
	char *av[] = {"/usr/bin/ls", NULL};

	while (1)
	{
		buffer = shell_prompt(buffer, buf_size, &characters);
		exec_stat = execve("/usr/bin/ls", av, NULL);
		if (exec_stat == -1)
			write(1, "./shell: No such file or directory\n", 35);
	}

	return (0);
}
