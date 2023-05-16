#include "shell.h"

int main(int argc, char **argv, char **envp)
{
        char *str = NULL;
        char *prompt = "#CisFun$ ";
        size_t n = 0, a;

        (void)envp;

        while (true)
        {
                write(1, prompt, 9);
                if (getline(&str, &n, stdin) == -1)
                {
                        perror("getline error");
                        exit(EXIT_FAILURE);
                }
// remove newline character from input string
                str[strcspn(str, "\n")] = '\0';

                a = fork();

                if (a == -1)
                {
                        perror("fork error");
                        exit(EXIT_FAILURE);
                }

                else if (a == 0)
                {
                        char *argv_holder[] = {str, NULL};
			// pass environ as the third argument


                        execve(str, argv_holder, envp);
                        perror("execve error");
                        exit(EXIT_FAILURE);
                }

                else
                {
                        wait(NULL);
                }
        }

        return 0;
}

