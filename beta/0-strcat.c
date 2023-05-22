#include "shell.h"

/**
 * _strcat - Concatenates 2 strings
 *
 * @src: source to be concatenated from
 * @dest: To be concatenated to
 * Return: Returns concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
