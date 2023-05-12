#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{
	//char **argv_holder;
	char *str = NULL;
	char *prompt = "#CisFun$ ";
	size_t n = 0, a;

	(void)envp;
	argv[argc] = NULL;

	while (true)
	{
		write(1, prompt, 9);
		if (getline(&str, &n, stdin) == -1)
		{
			perror("getline error");
			exit(EXIT_FAILURE);
		}

		a = fork();

		if (a == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}

		else if (a == 0)
		{
			str[strlen(str) -1] = '\0';
			char *argv_holder[] = {str, NULL};
			execve(str, argv_holder, NULL);
			perror("execve error");
			exit(EXIT_FAILURE);
		}

		else
		{
			wait(NULL);
		}
	}

	free(str);
	return 0;
}

