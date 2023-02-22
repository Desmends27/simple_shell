#include "shell.h"
static char *builtin_str[] = {
	"exit",
	"env",
	"cd"
};
int (*builtin_func[])(char **) = {
	&hsh_exit,
	&hsh_env,
	&hsh_cd
};
/**
 * lsh_num_builtins - return the index
 *
 * Return: index
 */
int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}
/**
 * hsh_exit - quit the shell
 * @args: pointer to the tokenized string
 *
 * Return: 1 always
 */
int hsh_exit(char **args)
{
	if (args != NULL)
		return (0);
	return (1);
}
/**
 * hsh_env - prints the envrionment variable
 * @args: function parameter
 * Return: int
 */
int hsh_env(char **args)
{
	char **env = __environ;

	while (*env && *args)
	{
		printf("%s\n", *env);
		env++;
	}
	return (1);
}
/**
 * hsh_cd - cd command
 * @args: argument count
 * Return: 1;
 */
int hsh_cd(char **args)
{
	if (args != NULL)
		chdir(args[1]);
	return (1);
}
/**
 * hsh_execute - excutes the command
 *
 *
 * @args: array of tokenized strings
 * @env: envirnonment variable
 * @argv: excutable name
 * Return: lauch with program to be excuted
 */
int hsh_execute(char **args, char **env, char *argv)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (launch(args, env, argv));
}
