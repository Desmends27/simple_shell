#include "shell.h"
/**
 * launch - calls the function to be executed
 * @args: function to be excuted passed as tokens
 * @env: call to the environ variable
 * @argv: print error message with it
 * Return: 0 on success
 */
int launch(char **args, char **env, char *argv)
{
	pid_t pid, __attribute__((unused))wpid;
	int status;

	/* fork if command is found */
	args[0] = file_check(args[0]);
	if (args[0] != NULL)
		pid = fork();
	if (pid == 0)
	{
		/*child process*/
		if (execve(args[0], args, env) == -1)
		{
			perror(argv);
			return (1);
		}
	}
	else if (pid < 0)
	{
		/*fork error*/
		free(args);
		perror(argv);
		return (1);
	}
	else
	{
		/* PARENT PROCESS */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while ((!WIFEXITED(status)) && (!WIFSIGNALED(status)));
	}
	return (1);
}

