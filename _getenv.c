#include "shell.h"
/**
 *_getenv - get environment variable
 *@name: name of variable to get
 *Return: return pointer to the variable
 */
char *_getenv(const char *name)
{
	/*extern char **environ;*/
	int i;
	char *char_symbol;
	size_t var_len;
	char *path;

	for (i = 0; environ[i] != NULL; i++)
	{
		char_symbol = strchr(environ[i], '=');

		if (char_symbol != NULL)
		{
			var_len = char_symbol - environ[i];

			if (strncmp(name, environ[i], var_len) == 0)
			{
				path = (char *)malloc(strlen(char_symbol + 1) + 1);
				strcpy(path, char_symbol + 1);

				return (path);
			}
		}
	}
	return (NULL);
}
