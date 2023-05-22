#include "shell.h"
char **token_split(char *str, const char *delimiter) {
    char **tokens = NULL;
    char *token = strtok(str, delimiter);
    int i = 0;

    while (token != NULL) {
        tokens = realloc(tokens, (i + 2) * sizeof(char *));
        if (tokens == NULL) {
            perror("Memory allocation error");
            exit(1);
        }

        tokens[i] = strdup(token);
        if (tokens[i] == NULL) {
            perror("Memory allocation error");
            exit(1);
        }

        token = strtok(NULL, delimiter);
        i++;
    }

    tokens[i] = NULL;
    return tokens;
}
