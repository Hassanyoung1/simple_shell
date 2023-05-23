#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char *_getenv_new(char *path)
{
	int i = 0;
	char *env_var;

	while ((env_var = environ[i]) != NULL) {
		char *str = strtok(env_var, "=");
		if (str != NULL && strcmp(str, path) == 0) {
			char *result = strdup(strtok(NULL, "="));
			if (result == NULL) {
				fprintf(stderr, "Memory allocation error\n");
			}
			return result;
		}
		i++;
	}

	return NULL;
}

