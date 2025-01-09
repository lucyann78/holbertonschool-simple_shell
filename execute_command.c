#include "shell.h"
/**
 * execute_command - Forks process, executes a command and waits if necessary.
 * @args: Array of tokens with command and arguments.
 *
 * Return: -1 on fork (Failure), 0 on (Success).
 */
int execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0) /* Child Process */
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (wait(&status) == -1)
		{
			perror("wait");
			return (-1);
		}
		if (WIFEXITED(status))
		{
			return (WIFEXITED(status));
		}
		else
		{
			return (-1);
		}
	}
	return (-1);
}
