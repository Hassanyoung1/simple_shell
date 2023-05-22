#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

char **token_split(char *path, char *delim)
{
    char **argv, *holder, *token;
    int count = 0, i = 0;

    if (path == NULL)
        return NULL;

    holder = strdup(path);
    token = strtok(holder, delim);
    if (token == NULL || holder == NULL)
        return NULL;

    while (token != NULL)
    {
        count++;
        token = strtok(NULL, delim);
    }
    free(holder);

    argv = malloc(sizeof(char *) * (count + 1));
    if (argv == NULL)
        return NULL;

    for (token = strtok(path, delim); token != NULL; token = strtok(NULL, delim))
    {
        char executable_path[MAX_PATH_LENGTH];
        strcpy(executable_path, token);
        strcat(executable_path, "/command");

        // Check if the constructed path is a valid executable file
        if (access(executable_path, X_OK) == 0)
        {
            argv[i] = strdup(token);
            i++;
        }
    }
    argv[i] = NULL;

    return argv;
}

int main()
{
    char *path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
    char **path_tokens = token_split(path, ":");

    if (path_tokens == NULL)
    {
        printf("Failed to split path\n");
        return 1;
    }

    int i = 0;
    while (path_tokens[i] != NULL)
    {
        printf("%s\n", path_tokens[i]);
        i++;
    }

    // Free allocated memory
    i = 0;
    while (path_tokens[i] != NULL)
    {
        free(path_tokens[i]);
        i++;
    }
    free(path_tokens);

    return 0;
}

