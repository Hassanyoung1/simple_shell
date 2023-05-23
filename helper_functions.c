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


/**
 * stringcmp - compares 2 strings
 *
 * @s1: First string to be compared
 * @s2: Second string to be compared
 * Return: Returns value of comparison (int)
 */
int stringcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; (s1[i] != '\0' && s2[i] != '\0'); i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (s1[i] - s2[i]);
}

/**
 * _strdup - returns a pointer to copy of given string
 *
 * @str: Given string
 * Return: pointer to copy of string on succes, NULL otherwise
 */
char *_strdup(char *str)
{
	char *ptr;
	int i, j;

	if (str == NULL)
		return (NULL);

	for (j = 0; str[j] != '\0'; j++)
	{

	}

	ptr = malloc(sizeof(char) * (j + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';
	return (ptr);
}

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

/**
 * *_strcpy - copies string pointed by SRC to buffer pointed by DEST
 *
 * @src: points to string to be copied
 * @dest: points to destination buffer
 * Return: Returns pointer to DEST
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest != NULL)
	{
		for (i = 0; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
		return (dest);
	}
	else
	{
		return (NULL);
	}
}
