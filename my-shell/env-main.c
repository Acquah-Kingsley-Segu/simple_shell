#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[], char const *envp[])
{
	size_t i;
	char *token;
	char *directories;
	char env_var[1024 * 1024];
	i = 0;
	while (envp[i] != NULL)
	{

		strcpy(env_var, envp[i]);
		token = strtok(env_var, "=");
		if (strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			directories = token;
			token = strtok(directories, ":");
			while (token != NULL)
			{
				printf("%s\n", token);
				token = strtok(NULL, ":");
			}
		}
		i += 1;
	}
	return (0);
}
