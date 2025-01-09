#include "shell.h"
/**
 * env_fetch - Verifies tokens.
 * @args: String of arguments given.
 * @input: User input string.
 * @count: Fixed number.
 *
 * Return: -1 on (Failure), 0 on (Success).
*/
int env_fetch(char **args, char *input, int count)
{
	char **env = environ;
	unsigned int i = 0;

	if (strcmp(args[0], "exit") == 0)
	{
		free(input);
		return (-1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (env[i] != NULL)
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	else if (find_or_execute_command(args) == -1)
		printf("./hsh: %d: %s: not found\n", count, args[0]);

	return (0);
}
