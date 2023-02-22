#include "shell.h"
/**
 * readline - reads the line entered by the user
 * @eof: value of eof condtion
 * Return: pointer to the read string
 */
char *readline(int *eof)
{
	char *input = NULL;
	size_t bufsize = 0;
	*eof = getline(&input, &bufsize, stdin);
	return (input);
}
