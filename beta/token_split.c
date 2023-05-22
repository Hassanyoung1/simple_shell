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

	for (token = strtok(path, delim); token != NULL; token = strtok(NULL, delim))
	{
		argv[i] = token;
		i++;
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * free_vector - frees a given argumnet vector
 *
 * @argv: argument vector to be freed
 * Return: nothing
 */
void free_vector(char **argv)
{
	int i;

	/*New Addition:*/
	if (argv == NULL)
		return;

	for (i = 0; argv[i] != NULL; i++)
	{
		if (argv[i] != NULL)
			free(argv[i]);
	}
	free(argv);
}
