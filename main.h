#ifndef MAIN_H
#define MAIN_H

#define LIM_ARGS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
int main(int argc, char *argv[], char *envp[]);
int _strcmp(const char *str1, const char *str2);
int _strcpy(char *receiver, const char *sender);
int _spliting(char *input_command, char **argv);
int exec_command(char **argv);
void _env_variables(char **envp);
size_t _strlen(char *str);
char *_strdup(const char *str);
char *get_path(const char *command);
char *_getenv(const char *environ_var);

#endif
