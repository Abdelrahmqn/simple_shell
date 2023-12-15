#ifndef MAIN_H
#define MAIN_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
#define LIM_ARGS 100
#define DELIM " \t\n"

int main(int argc, char **argv, char **envp);
char *_readinput(void);

char **_splitting(char *line);

void _free1(char *variable);
void _free2(char **variable);
void _free3(char **variable3);

int exec_command(char **cmd, char **argv, char **envp);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcpy(char *receiver, const char *sender);
char *_strdup(const char *str);
void _env_variables(char **envp);
size_t _strlen(const char *str);
char *_getenv(const char *name);
char *full_path(char *command);
char *_strcat(char *dest, char *src);


#endif
