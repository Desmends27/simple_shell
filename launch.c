#include "shell.h"
/**
 * launch - starts the program to be excuted
 * @args: array of passed in arguments
 * @env: environment variables
 * @argv: name of excutale
 * Return: 1 always
 */
int launch(char **args, char **env, char *argv)
{
	pid_t pid = 0, __attribute__((unused))wpid;
	int status;

	args[0] = file_check(args[0]);
	if (args[0] != NULL)
		pid = fork();
	if (pid == 0)
	{
		/*child process*/
		if (execve(args[0], args, env) == -1)
		{
			printf("%s: No such file or directory\n", argv);
			return (1);
		}
	}
	else if (pid < 0)
	{
		/*failed process*/
		perror(argv);
	}
	else
	{
		/*parent process*/
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while ((!WIFEXITED(status)) && (!WIFSIGNALED(status)));
	}
	return (1);
}
