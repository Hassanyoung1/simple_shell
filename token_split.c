#include "shell.h"

/**
 * token_split - splits a string into tokens baesd on given delimiter
 *
 * @path: A string variable to be split
 * @delim: delimeter to be used for spliting
 * @argv: An array of array of strings
 * @argv_size: size of argv
 * Return: A pointer to splitted string
 */
void token_split(char *path, char *delim, char **argv, int argv_size)
{
	char *token;
	int count = 0, i = 0;

	if (path == NULL || argv == NULL || argv_size <= 0)
		return;

	token = strtok(path, delim);
	while (token != NULL && count < argv_size - 1)
	{
		argv[i] = malloc(_strlen(token) + 1);
		if (argv[i] == NULL)
		{
			free_token_holder(argv);
			perror("memory allocation");
			return;
		}

		_strcpy(argv[i], token);
		count++;
		i++;
		token = strtok(NULL, delim);
	}

	argv[i] = NULL;
}

/**
 * free_token_holder - frees alocated memory in token_holder
 *
 * @token_holder: holder to be freed
 * REturn: nothing
 */
void free_token_holder(char **token_holder)
{
	int i = 0;

	while (token_holder[i] != NULL)
	{
		free(token_holder[i]);
		i++;
	}
}
