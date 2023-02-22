#include "main.h"
/**
 * hsh_readline - reads the line to be inputed
 * @argv:
 * Return: a string
 */
char *hsh_readline()
{
	size_t bufsize = 0;
	char *line = NULL;
	size_t len;

	if ((getline(&line, &bufsize, stdin) == -1))
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("me");
			exit(EXIT_FAILURE);
		}
	}
    /* remove trailing newline character, if present */
	len = strlen(line);
	if ((len > 0) && (line[len - 1] == '\n'))
	{
		line[len - 1] = '\0';
	}
	return (line);
}
