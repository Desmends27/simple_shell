#include "shell.h"
/**
 * tokenize - uses strtok to tokenize the string
 * Return: pointer to an array of char *
 */
#define BUFSIZE 64
#define DELIM " \t\r\n\a"
char **tokenize(char *line)
{
	/*declaration of various fucntions*/
	char **toks = malloc(sizeof(char *) * BUFSIZE);
	int position = 0;
	char *token, **token_backup;
	int bufsize = BUFSIZE;

	/*allocation error*/
	if (toks == NULL)
	{
		free(toks);
		perror("hsh");
	}
	token = strtok(line, DELIM);
	/*Store  token in toks*/
	while (token != NULL)
	{
		toks[position] = token;
		position++;
		/*not enough memory*/
		if (position >= BUFSIZE)
		{
			bufsize += BUFSIZE;
			token_backup = toks;
			toks = realloc(toks, position * sizeof(char *));
			if (toks == NULL)
			{
				free(token_backup);
				printf("allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	toks[position] = NULL;
	return (toks);
}

