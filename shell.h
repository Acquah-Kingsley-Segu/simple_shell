#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>

char *shell_prompt(char *, size_t, ssize_t *);
int exit_check(char *, ssize_t);
#endif
