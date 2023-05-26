#include "shell.h"

/**
 * token_split - splits a string into tokens baesd on given delimiter
 *
 * @path: A string variable to be split
 * @delim: delimeter to be used for spliting
 * Return: A pointer to splitted string
 */

char **token_split(char *path, char *delim)
{
	char **argv, *holder, *token;
	int count = 0, i = 0;

	if (path == NULL)
		return (NULL);

	holder = _strdup(path);
	token = strtok(holder, delim);
	if (token == NULL || holder == NULL)
		return (NULL);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(holder);

	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
		return (NULL);

	for (token = strtok(path, delim); token != NULL; token = strtok(NULL, delim))
	{
		argv[i] = token;
		i++;
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * free_vector - frees string vector and string
 *
 * @argv_ptr: A pointer to  string vector to be freed
 * @str_ptr: A pointer to string to be freed
 * Return: Nothing
 */

void free_vector(char ***argv_ptr, char **str_ptr)
{
	int i;
	char **argv = *argv_ptr;
	char *str = *str_ptr;

	if (argv != NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			if (argv[i] != NULL)
			{
				free(argv[i]);
				argv[i] = NULL;
			}
			argv[i] = NULL;
		}

		free(argv);
		*argv_ptr = NULL;
	}

	if (str != NULL)
	{
		free(str);
		*str_ptr = NULL;
	}
	*str_ptr = NULL;
}
