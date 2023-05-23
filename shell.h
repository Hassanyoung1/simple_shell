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
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(char *str1, char *str2, int n);


/*void fork_check(int pid);*/
void fork_check(char **argv, char **envp, pid_t pid);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *path_get(char *command);
char *path_get_new(char *command);
bool check_builtin(char *str);

char *_getenv(char *name);
/* EXTERNS*/
extern char **environ;

/*MAIN FUNCTIONS*/
char **token_split(char *path, char *delim);
void prompt_exect(char **argv, char **envp);


#endif

