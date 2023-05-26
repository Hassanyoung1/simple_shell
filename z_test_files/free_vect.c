#include "shell.h"

/**
 * free_vector - frees string vector
 *
 * @argv: A string vector to be freed
 * Return: A pointer to splitted string
 */

void free_vector(char **argv)
{
	if (argv == NULL)
		return;

	for (int i = 0; argv[i] != NULL; i++)
	{
		if (argv[i] != NULL)
		{
			free(argv[i]);
			argv[i] = NULL;
		}
		else
		{
			argv[i] = NULL;
		}
	}

	free(argv);
	argv = NULL;
}

void free_vector(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

void free_vector(char **argv, char *str)
{
	free_vector(argv);
	free_vector(str);
}

