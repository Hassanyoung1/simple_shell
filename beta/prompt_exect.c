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

		str = call_getline(str, n);
		if (stringcmp(str, "exit") == 0)
			break;

		argv = token_split(str, " ");

		a = fork();

		fork_check(argv, envp, a);
		free(str);
	}
	free(str);
}
/**
 * fork_check - checks fork status and implements execve
 *
 * @pid: pid of a given fork command
 * @argv: Argument vector
 * @envp: Pointer to environment variable
 * Return: nothing
 */

void fork_check(char **argv, char **envp, int pid)
{
	if (pid == 0)
	{
		execve(argv[0], argv, envp);
		perror(argv[0]);
		free_vector(argv);
		exit(EXIT_FAILURE);
	}
	else if (pid == -1)
	{	perror("fork error");
		free_vector(argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (wait(NULL) == -1)
		{
			perror("wait error");
			free_vector(argv);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * call_getline - gets input from user and handles related errors
 *
 * @str: string to hold collected user input
 * @n: size of str
 * Return: nothing
 */
char *call_getline(char *str, size_t n)
{
	if (getline(&str, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(str);
			exit(98);
		}

		perror("getline error");
		free(str);
		exit(EXIT_FAILURE);
	}
	str[_strlen(str) - 1] = '\0';

	return (str);
}

int my_access(const char* path, int mode) {
    if (access(path, mode) == 0) {
        // The file has the specified permissions
        return 0;
    } else {
        // The file does not have the specified permissions or does not exist
        return -1;
    }
}
