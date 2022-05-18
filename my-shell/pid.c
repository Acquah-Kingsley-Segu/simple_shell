#include <stdio.h>
#include <unistd.h>

int main(int ac, char const **av)
{
	while (*av)
	{
		printf("%s\n", *av++);
	}

	return (0);
}
