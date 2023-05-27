#include "shell.h"

/**
 * main - main function for the simple shell
 *
 * @argc: The argument count
 * @argv: The argument vector
 * Return: nothing
 */

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		prompt_exect(argv);
	}
	perror(": syntax error");
	exit(EXIT_FAILURE);
	return (0);
}
