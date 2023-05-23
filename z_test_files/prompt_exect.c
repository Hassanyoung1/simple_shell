#include "shell.h"

/**
 * prompt_exect - provides a prompt and execute simple shell command
 *
 * @argv: pointer to argument vector
 * @envp: pointer to path environ string
 * Return: nothing
 */
void prompt_exect(char **argv, char **envp)
{
	char *str = NULL;
	size_t n  = 0;
	int a;

	while (true)
	{
		write(1, "$ ", 2);

		call_getline(str, n);
		argv = token_split(str, " ");

		a = fork();
		if (a == 0)
		{
			execve(argv[0], argv, envp);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else if (a == -1)
		{	perror("fork error");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (wait(NULL) == -1)
			{
				perror("wait error");
				exit(EXIT_FAILURE);
			}
		}
	}
	free(str);
	free_vector(argv);
}

/**
 * call_getline - gets input from user and handles related errors
 *
 * @str: string to hold collected user input
 * @n: size of str
 * Return: nothing
 */
void call_getline(char *str, size_t n)
{
	if (getline(&str, &n, stdin) == -1)
	{
		if (feof(stdin))
			return;

		perror("getline error");
		free(str);
		exit(EXIT_FAILURE);
	}
	str[_strlen(str) - 1] = '\0';
}
