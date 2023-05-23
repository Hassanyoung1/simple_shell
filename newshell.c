#include "shell.h"

/**
 * main - main function for the simple shell
 *
 * @argc: The argument count
 * @argv: The argument vector
 * @envp: the environment path
 * Return: nothing
 */

int main(int argc, char **argv, char **envp)
{
	if (argc == 1)
	{
		prompt_exect(argv, envp);
	}
	perror(": syntax error");
	exit(EXIT_FAILURE);
	return (0);
}
