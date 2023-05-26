#include "shell.h"


void token_split(char *path, char *delim, char **argv, int argv_size)
{
	char *token;
	int count = 0, i = 0;

	if (path == NULL || argv == NULL || argv_size <= 0)
		return;

	token = strtok(path, delim);
	while (token != NULL && count < argv_size - 1)
	{
		argv[i] = token;
		count++;
		i++;
		token = strtok(NULL, delim);
	}

	argv[i] = NULL;
}

