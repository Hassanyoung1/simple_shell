#include "shell.h"
int main(int argc, char **argv, char **env) {
    int i = 0, len = 0, a;
    size_t n = 0;
    char **temp, *path, *new_temp, *str;

    path = getenv("PATH");
    printf("%s: \n", path);

    temp = token_split(path, ":");

    while (temp[i] != NULL) {
        printf("%s \n", temp[i]);
        i++;
    }
    i = 0;

    getline(&str, &n, stdin);
    str[strlen(str) - 1] = '\0';

    // Close the file descriptor returned by getline
    fclose(stdin);

    while (temp[i] != NULL) {
        len = strlen(temp[i]);
        new_temp = malloc(len + strlen(str) + 2);

        if (new_temp == NULL) {
            perror("Memory allocation error");
            exit(1);
        }

        strcpy(new_temp, temp[i]);
        new_temp[len] = '/';
        strcat(new_temp, str);

        // Execute the command using execv
        a = fork();
        if (a == 0) {
            char *command[] = {new_temp, NULL};
            execv(command[0], command);
            perror("Execution failed");
            exit(1);
        }

        free(new_temp);
        i++;
    }

    return 0;
}

