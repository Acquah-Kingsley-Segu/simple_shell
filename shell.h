#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>

char *shell_prompt(char *, size_t, ssize_t *);
char **split_str(char *);
int exit_check(char *, ssize_t);
void command_exec(char *line, ssize_t nread);
/* int _getline(char *, int *); */
#endif
