#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	size_t i;
	struct stat st;
	if (argc < 2)
	{
		printf("Usage: %s path_to_file ...\n", argv[0]);
		return (1);
	}

	i = 1;
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (stat(argv[i], &st) == 0)
		{
			printf(" Found\n");
		}
		else
		{
			printf(" Not Found\n");
		}
		i += 1;
	}

	return (0);
}
