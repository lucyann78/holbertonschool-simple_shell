#include "shell.h"
/**
 * _getenv - Finds the environment.
 * @name: Name of the environment variable.
 *
 * Return: The value after '=' (Success), NULL (Failure).
 */
char *_getenv(const char *name)
{
	size_t length = strlen(name);
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, name, length) == 0 && (*env)[length] == '=')
			return (&(*env)[length + 1]); /* Return the value after '=' */
		env++;
	}
	return (NULL); /* Environment variable not found */
}

