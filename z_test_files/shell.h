#ifndef SHELL_H
#define SHELL_H


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**helper function*/
void free_vector(char **argv);
int _strlen(char *str);
char *call_getline(char *str, size_t n);


char **token_split(char *path, char *delim);
void prompt_exect(char **argv, char **envp);


#endif

