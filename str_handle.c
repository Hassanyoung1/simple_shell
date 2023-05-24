#include "shell.h"

/**
 * str_check - checks if str is entirely spaces or newline or otherwise
 *
 * @str: string to be checked
 * Return: 1 for newlines, 0 for spaces and -1 otherwise
 */

int str_check(char *str)
{
	int i = 0;
	char currentChar = str[i];

	while (currentChar != '\0')
	{
		if (currentChar != ' ' && currentChar != '\n')
		{
			return (-1);
		}

		currentChar = str[++i];
	}

	if (currentChar == '\0' && i > 0)
	{
		if (currentChar == ' ')
		{
			return (0);
		}
		else if (currentChar == '\n')
		{
			return (1);
		}
	}

	return (-1);
}
