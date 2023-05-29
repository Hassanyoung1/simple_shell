#include "shell.h"

#define MAX_TOKENS 200

/**
 * prompt_exect - provides a prompt and execute simple shell command
 * @argv: pointer to argument vector
 * Return: nothing
 */
void prompt_exect(char **argv)
{
	char *holder, *str = NULL, *token_holder[MAX_TOKENS];
	size_t n  = 0;
	int a, count = 0;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		str = call_getline(str, n, &count);
		if (*str == '\n')
		{	free(str);
			continue;
		}
		if (token_split(str, " ", token_holder, MAX_TOKENS) == -1)
		{	free_token_holder(token_holder); /*freed str in func*/
			continue;
		}
		else if (check_builtin(token_holder[0]))
		{free_token_holder(token_holder); /*str freed in getline*/
			continue;
		}
		holder = path_get(token_holder[0]);

		if (holder != NULL)
		{
			if (access(token_holder[0], X_OK) == -1)
			{a = fork();
				fork_check(token_holder, holder, a);
				free(holder);
			}
			else
			{a = fork();
				fork_check(token_holder, holder, a);
				check_builtin("exit2");
			}
			continue;
		}
		else if (token_holder == NULL || holder == NULL)
			error_handle(argv, token_holder[0], count);
	}
}
/**
 * fork_check - checks fork status and implements execve
 *
 * @pid: pid of a given fork command
 * @argv: Argument vector
 * @holder: holds the full, concatenated path of command to run
 * Return: nothing
 */

void fork_check(char **argv, char *holder, int pid)
{
	if (pid == 0)
	{
		execve(holder, argv, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid == -1)
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
	free_token_holder(argv);
}

/**
 * call_getline - gets input from user and handles related errors
 *
 * @str: string to hold collected user input
 * @n: size of str
 * @count: Total number of command entered by user
 * Return: nothing
 */
char *call_getline(char *str, size_t n, int *count)
{
	int check;

	sig_str sig_cont;

	sig_cont.flag = 0;
	init_handle_sigs(&sig_cont);

	if (getline(&str, &n, stdin) == -1)
	{
		(*count)++;
		free(str);
		if (isatty(STDIN_FILENO && str == NULL))
		{
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		exit(EXIT_SUCCESS);
	}

	check = str_check(str);
	if (str[0] == '\0' && !isatty(STDIN_FILENO))
	{
		(*count)++;
		free(str);
		exit(EXIT_SUCCESS);
	}
	if (check == 0 && isatty(STDIN_FILENO))
	{
		(*count)++;
		free(str);
		return ("\n");
	}
	(*count)++;

	str[_strlen(str) - 1] = '\0';

	return (str);
}

/**
 * path_get -  concatinate command with path
 * @command: commmand pass by user
 * Return: success return concatinated path, else Null
 **/
char *path_get(char *command)
{
	char *path_holder[MAX_TOKENS], *holder, *path_copy, *path, exec_path[100];
	int i = 0;

	if (command == NULL)
		return (NULL);
	if (access(command, X_OK) == 0)
		return (command);
	path  = _getenv("PATH");
	if (path == NULL)
	{
		free(path);
		return (NULL);
	}
	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		free(path);
		free(path_copy);
		return (NULL);
	}
	token_split(path_copy, ":", path_holder, MAX_TOKENS);

	while (path_holder[i] != NULL)
	{
		_strcpy(exec_path, path_holder[i]);
		_strcat(exec_path, "/");
		_strcat(exec_path, command);
		_strcat(exec_path, "\0");
		if (access(exec_path, X_OK) == 0)
		{
			free(path);
			holder = _strdup(exec_path);
			free_token_holder(path_holder);
			return (holder);
		}
		i++;
	}
	free(path);
	free_token_holder(path_holder);
	return (NULL);
}

/**
 * check_builtin - checks if given command is builtin
 *
 * @str: command to be checked
 * Return: boolean value
 */
bool check_builtin(char *str)
{
	char **env;
	int i = 0;

	if (str == NULL)
		return (false);

	if (stringcmp(str, "exit") == 0)
	{
		free(str);
		exit(EXIT_SUCCESS);
	}
	else if (stringcmp(str, "exit2") == 0)
	{
		if (!isatty(STDIN_FILENO)) /*non dynam. alloc str. passed*/
			exit(2);
		return (false);
	}

	else if (stringcmp(str, "env") == 0)
	{
		env = environ;

		while (env[i] != NULL)
		{
			write(1, env[i], _strlen(env[i]));
			write(1, "\n", 1);
			i++;
		}
		return (true);
	}
	return (false);
}
