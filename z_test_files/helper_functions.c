#include "shell.h"

/**
 * _strlen - Returns the length of a string
 *
 * @str: String integer given to the function
 * Return: Returns number of strings
 */
int _strlen(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
