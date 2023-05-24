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

/**
 * error_handle - handles errors
 *
 * @curr_name: name of current command
 * @argv_name: name of main program
 * @count: number of total commands by user
 * Return: nothing
 */

/*
 * void error_handle(char *curr_name, char *argv_name, int count)
* {
*	char message[100];
*	int msg_len = 0;
*	_strcpy(message, "not found");
*	msg_len = _strlen(message);
*
*	write(STDERR_FILENO, argv_name, _strlen(argv_name));
*	write(STDERR_FILENO, ": ", 2);
*	write(STDERR_FILENO, 1, );
*	write(STDERR_FILENO, ": ", 2);
*	write(STDERR_FILENO, message, len);
*	write(STDERR_FILENO, "\n", 1);
*}
*/
