#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

static char *get_buf;
static ssize_t size = 32650;

int _getline(char *buffer, int *buf_size)
{
	size = read(0, get_buf, size);
	printf("get_buf: %s\nsize: %li", get_buf, size);
}
