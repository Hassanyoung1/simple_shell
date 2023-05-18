#ifndef SHELL_H
#define SHELL_H


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**HELPER FUNCTIONS*/
void free_vector(char **argv);
int _strlen(char *str);
char *call_getline(char *str, size_t n);
int stringcmp(char *s1, char *s2);
/*void fork_check(int pid);*/
void fork_check(char **argv, char **envp, int pid);
char *_strdup(char *str);



/*MAIN FUNCTIONS*/
char **token_split(char *path, char *delim);
void prompt_exect(char **argv, char **envp);


#endif

