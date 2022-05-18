#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>

ssize_t shell_prompt(char *line, size_t line_len, FILE *stream);
int execute_command(char *cmd, char **av, char **env);
char **str_split(char *str, char const *delim);
char **find_paths(char *env[]);
char *find_command(char *cmd, char **envp);

#endif