#include "shell.h"
/**
 * parse_input - Analyzes the user input and tokenizes it.
 * @input: User input string.
 *
 * Return: Array of tokens.
 */
char **parse_input(char *input)
{
	char **arguments = malloc(MAX_ARGS * sizeof(char *));
	char *token;
	int number_of_arguments = 0;

	if (!arguments)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " \n");
	while (token != NULL && number_of_arguments < MAX_ARGS - 1)
	{
		arguments[number_of_arguments] = token;
		token = strtok(NULL, " \n");
		number_of_arguments++;
	}
	arguments[number_of_arguments] = NULL;
	return (arguments);
}
