#include "shell.h"

/**
 * _getenv - Gets the specified environment variable
 *
 * @path: path to look for
 * Return: pointer to the the var. on success, NULL otherwise
 */

char *_getenv(char *path)
{
	char **env = NULL;
	char *str, *result;
	int i = 0;

	while (environ[i] != NULL)
	{
		env = (char **)realloc(env, (i + 2) * sizeof(char *));
		env[i] = strdup(environ[i]);
		i++;
	}
	i = 0;

	while (env[i] != NULL)
	{
		str = strtok(env[i], "=");
		if (str == NULL)
			return (NULL);
		if (stringcmp(str, path) == 0)
		{
			str = strtok(NULL, "=");
			result = strdup(str);
			free(env);
			return (result);
		}

		i++;
	}
	free(env);
	return (NULL);
}
