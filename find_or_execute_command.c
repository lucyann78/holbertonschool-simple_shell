#include "shell.h"
/**
 * find_or_execute_command - Checks the command input for execution.
 * @args: Array of tokens with args[0] being the command.
 *
 * Return: -1 if the command is found (Success), 0 if not found (Failure).
 */
int find_or_execute_command(char **args)
{
	if (access(args[0], X_OK) == 0)
	{
		return (execute_command(args));
	}
	else
	{
		char *path = _getenv("PATH");
		char *path_copy = strdup(path);
		char *dir = strtok(path_copy, ":");

		while (dir != NULL)
		{
			char *command_path = malloc(strlen(dir) + strlen(args[0]) + 2);

			sprintf(command_path, "%s/%s", dir, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				args[0] = command_path;
				execute_command(args);
				free(command_path);
				free(path_copy);
				return (0);
			}
			free(command_path);
			dir = strtok(NULL, ":");
		}
		free(path_copy);
		return (-1);
	}
	return (0);
}

