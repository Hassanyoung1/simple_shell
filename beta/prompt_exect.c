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
	char *holder, *str = NULL;
	size_t n  = 0;
	pid_t a;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		str = call_getline(str, n);
		//if (stringcmp(str, "exit") == 0)
		//	break;
		if (*str == '\n')
			continue;
		else if (check_builtin(str))
			continue;

		argv = token_split(str, " ");
		if (argv == NULL)
		{
			free_vector(argv);
			continue;
		}
		holder = path_get(argv[0]);

		if (holder != NULL)
		{
			argv[0] = holder;

			a = fork();

			fork_check(argv, envp, a);
		}
		if (argv == NULL || holder == NULL)
			perror(argv[0]);
		free(str);
		str = NULL;
	}
	//free_vector(argv);
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
			/*perror("end of file");*/
			free(str);
			/*changed from exit 98*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline error");
			free(str);
			exit(EXIT_FAILURE);
		}
	}
	/*new addition: checks if getline got only newline*/
	else if (*str == '\n')
		return ("\n");
	str[_strlen(str) - 1] = '\0';

	return (str);
}
<<<<<<< HEAD

int my_access(const char* path, int mode) {
    if (access(path, mode) == 0) {
        // The file has the specified permissions
        return 0;
    } else {
        // The file does not have the specified permissions or does not exist
        return -1;
    }
=======
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
	path  = getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	/*Added path check*/
	printf("path is: %s\n", path_copy);
	path_holder = token_split(path_copy, ":");

	while (path_holder[i] != NULL)
	{
		strcpy(exec_path, path_holder[i]);
		strcat(exec_path, "/");
		strcat(exec_path, command);
		strcat(exec_path, "\0");

		if (access(exec_path, X_OK) == 0)
		{
			holder = strdup(exec_path);
			printf("concatenated str is: %s\n", holder);
			return (holder);
		}
		i++;
	}
	//if (path_holder != NULL || *path_holder != NULL)
	//	free_vector(path_holder);
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

	if (strcmp(str, "exit") == 0)
		exit(EXIT_SUCCESS);

	else if (strcmp(str, "env") == 0)
	{
		env = environ;

		while (env[i] != NULL)
		{
			write(1, env[i], strlen(env[i]));
			write(1, "\n", 1);
			i++;
		}
		return (true);
	}
	return (false);
>>>>>>> 21b54c3f91eaa690b5d124fd517103f672d56102
}
