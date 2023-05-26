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
	char *holder, *str = NULL, **token_holder;
	size_t n  = 0;
	pid_t a;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		str = call_getline(str, n);

		if (*str == '\n')
		{
			free_vector(NULL, &str);
			continue;
		}

		token_holder = token_split(str, " ");
		if (token_holder == NULL)
		{
			free_vector(&token_holder, &str);
			continue;
		}
		else if (check_builtin(token_holder[0]))
		{
			free_vector(&token_holder, &str);
			continue;
		}
		holder = path_get(token_holder[0]);

		if (holder != NULL)
		{
			token_holder[0] = holder;
			/*free_vector(NULL, &holder);*/

			a = fork();
			fork_check(token_holder, envp, a);
		}

		else if (token_holder == NULL || holder == NULL)
		{
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			perror(token_holder[0]);
			/*free_vector(&token_holder, &holder);*/
			free_vector(&argv, NULL);
		}
		free(str);
	}
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
	sig_str sig_cont;

	sig_cont.flag = 0;
	init_handle_sigs(&sig_cont);

	if (getline(&str, &n, stdin) == -1)
	{
		free(str);
		if (isatty(STDIN_FILENO && str == NULL))
		{
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}

		exit(EXIT_SUCCESS);
	}

	else if (str_check(str) == 0 && !isatty(STDIN_FILENO))
	{
		free_vector(NULL, &str);
		exit(EXIT_SUCCESS);
	}
	/*else if (signal(SIGINT, handle_sigs) == SIG_DFL)*/
	/*{*/
	/*	free(str);*/
	/*	return ("\n");*/
	/*}*/

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
	char **path_holder, *holder, *path_copy, *path;
	char exec_path[100];
	int i = 0;

	if (access(command, X_OK) == 0)
		return (command);

	path  = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		free_vector(NULL, &path_copy);
		return (NULL);
	}

	path_holder = token_split(path_copy, ":");

	while (path_holder[i] != NULL)
	{
		_strcpy(exec_path, path_holder[i]);
		_strcat(exec_path, "/");
		_strcat(exec_path, command);
		_strcat(exec_path, "\0");

		if (access(exec_path, X_OK) == 0)
		{
			holder = _strdup(exec_path);
			/*free_vector(path_holder, NULL);*/
			return (holder);
		}
		i++;
	}
	free_vector(&path_holder, &path_copy);
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
		exit(EXIT_SUCCESS);

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
