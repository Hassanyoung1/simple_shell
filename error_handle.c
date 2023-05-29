#include "shell.h"

/**
 * error_handle - Handles errors
 *
 * @argv: The shells argument vector
 * @command: user-passed command
 * @count: count of ALL commands in the program
 * Return: nothing
 */
void error_handle(char **argv, char *command, int count)
{
	char error_message[100];
	char command_number[10];
	int err_len = 0, temp, i, count_len = 0;

	if (command == NULL)
		return;
	temp = count;
	while (temp != 0)
	{
		temp /= 10;
		count_len++;
	}
	temp = count;
	for (i = count_len - 1; i >= 0; i--)
	{
		command_number[i] = '0' + (temp % 10);
		temp /= 10;
	}
	command_number[count_len] = '\0';

	fflush(NULL);
	if (access(command, X_OK) == -1)
	{
		err_len = _print_err_prompt(argv[0], command_number, command);
		err_len += write(STDERR_FILENO, ": not found\n", 12);
		free(command);
		if (!isatty(STDIN_FILENO))
			exit(127);
		return;
	}

	if (access(command, F_OK) == -1)
	{
		err_len = _print_err_prompt(argv[0], command_number, command);
		err_len += write(STDERR_FILENO, ": Permission denied\n", 20);
		return;
	}

	error_message[err_len] = '\0';
	perror(error_message);
}

/**
 * _print_err_prompt - prints error before error message
 *
 * @argv_name: name of the program
 * @command_number: number of commands in string
 * @command: the command passed
 * Return: total number of characters printed
 */

int  _print_err_prompt(char *argv_name, char *command_number, char *command)
{
	int err_len = 0;

	err_len = write(STDERR_FILENO, argv_name, _strlen(argv_name));
	err_len += write(STDERR_FILENO, ": ", 2);
	err_len += write(STDERR_FILENO, command_number, _strlen(command_number));
	err_len += write(STDERR_FILENO, ": ", 2);
	err_len += write(STDERR_FILENO, command, _strlen(command));

	return (err_len);
}
