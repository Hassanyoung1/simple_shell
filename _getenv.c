#include "shell.h"
/**
 *_getenv - get environment variable
 *@name: name of variable to get
 *Return: return pointer to the variable
 */
char *_getenv(char *name)
{
	/*extern char **environ;*/
	int i;
	char *char_symbol;
	size_t var_len;
	char *path;

	for (i = 0; environ[i] != NULL; i++)
	{
		char_symbol = _strchr(environ[i], '=');

		if (char_symbol != NULL)
		{
			var_len = char_symbol - environ[i];

			if (_strncmp(name, environ[i], var_len) == 0)
			{
				path = (char *)malloc(_strlen(char_symbol + 1) + 1);
				_strcpy(path, char_symbol + 1);

				return (path);
			}
		}
	}
	return (NULL);
}

/**
 * _strchr - locates a character in a string
 *
 * @s: A C String
 * @c: character to be located
 * Return: Returns a pointer to the first occurence of c or null otherwise
 */
char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
		{
			return (s);
		}
	}
	if (*s == c)
	{
		return (s);
	}
	return (0);
}

/**
 * _strncmp - compares strings based on given n
 * @str1: first string
 * @str2: second string
 * @n: number of chars to compare
 * Return: 0 on success, other numbers on failure
 */

int _strncmp(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; (str1[i] != '\0' || str2[i] != '\0') && i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}

	return (0);
}

