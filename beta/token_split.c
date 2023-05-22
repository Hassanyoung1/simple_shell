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
	int my_acces = access(holder, X_OK);
	int my_acces = access(holder, F_OK);
	int my_acces = access(holder, W_OK);
	int my_acces = access(holder, R_OK);

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
	  if (my_access(holder, F_OK) == 0) {
        printf("File '%s' exists\n", holder);
    } else {
        printf("File '%s' does not exist\n", holder);
    }

    // Check if the file is readable
    if (my_access(holder, R_OK) == 0) {
        printf("File '%s' is readable\n", holder);
    } else {
        printf("File '%s' is not readable\n", holder);
    }

    // Check if the file is writable
    if (my_access(holder, W_OK) == 0) {
        printf("File '%s' is writable\n", holder);
    } else {
        printf("File '%s' is not writable\n", holder);
    }

    // Check if the file is executable
    if (my_access(holder, X_OK) == 0) {
        printf("File '%s' is executable\n", holder);
    } else {
        printf("File '%s' is not executable\n", holder);
    }

    return 0;
}
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
