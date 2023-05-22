#ifndef SHELL_H
#define SHELL_H


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


/* Helper functions */
void free_vector(char **argv);
int _strlen(char *str);

char **token_split(char *str, const char *delimiter);
//char **token_split(char *path, char *delim);
void prompt_exect(char **argv, char **envp);




#endif
