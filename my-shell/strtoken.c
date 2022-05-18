#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **split_str(char *);

int main()
{
	char mystr[] = "HELLO EVERYONE IN MY WORLD.";
	char **mystr_arr;
	mystr_arr = split_str(mystr);
	while (*mystr_arr)
	{
		printf("%s\n", *mystr_arr++);
	}
}

char **split_str(char *str)
{
	char **str_arr;
	str_arr = malloc(sizeof(char *) * 1024);
	char *token;
	int i;
	token = strtok(str, " ");
	i = 0;
	while (token != NULL)
	{
		str_arr[i] = token;
		i += 1;
		token = strtok(NULL, " ");
	}
	free(str_arr);
	return str_arr;
}