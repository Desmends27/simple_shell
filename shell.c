#include "main.h"
/**
 * main - calls to function to start the shell
 * @argc: argument count
 * @argv: argument vector
 * @env: environ variable
 * Return: 1 always
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv
		, char **env)
{
	char *line;
	int status = 1;
	int mode;
	char **args;

	/* loop to initiate the shell */
	while (status)
	{
		/*check for interacitive mode*/
		mode = isatty(STDIN_FILENO);
		if (mode != 0)
		{
			write(STDOUT_FILENO, "$ ", 3);
		}
		line = strdup(hsh_readline());
		if (line == NULL)
		{
			free(line);
			printf("\n");
			exit(1);
		}
		/* tokenize the string */
		args = tokenize(line);
		/*lauch the command*/
		status = launch(args, env, argv[0]);
		free(args);
		free(line);
	}
	return (1);
}