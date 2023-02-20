#include "main.h"
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

	pid = fork();
	if (pid == 0)
	{
		/*child process*/
		if (execve(args[0], args, env) == -1)
		{
			free(args);
			perror(argv);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/*fork error*/
		free(args);
		perror(argv);
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
