#include "shell.h"
/**
 * main - loop of the shell program
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 * Return: 1 always
 *
 */
int main(__attribute__((unused))int argc, char **argv, char **env)
{
	char *line;
	char **args;
	int status = 1;
	int mode;
	int eof;

	while (status)
	{
		mode = isatty(STDIN_FILENO);
		if (mode != 0)
		{
			write(STDOUT_FILENO, "$ ", 3);
		}
		line = readline(&eof);
		if (eof == -1)
		{
			exit(EXIT_SUCCESS);
		}
		args = tokenize(line);
		status = launch(args, env, argv[0]);
	}
	return (1);
}
