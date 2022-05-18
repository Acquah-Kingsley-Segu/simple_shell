#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	ssize_t nread;
	char *line = NULL;
	char *PROMT_STR = "$ ";
	int PROMPT_LEN = 2;
	size_t LINE_LEN = 0;
	while (1)
	{
		write(STDOUT_FILENO, PROMT_STR, PROMPT_LEN);
		nread = getline(&line, &LINE_LEN, stdin);
		if (nread != -1)
		{
			write(STDOUT_FILENO, line, LINE_LEN);
			LINE_LEN = 0;
		}
		else
		{
			break;
		}
	}
	exit(EXIT_SUCCESS);
}
