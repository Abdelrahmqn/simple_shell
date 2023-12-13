#ifndef MAIN_H
#define MAIN_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define LIM_ARGS 100
#define DELIM " \t\n"

int main(int argc, char **argv, char **envp);
char *_readinput(void);

char **_splitting(char *line);

void _free1(char *variable);
void _free2(char **variable);
void _free3(char **variable3);

int exec_command(char **cmd, char **argv, char **envp);

int _strcmp(const char *str1, const char *str2);
int _strcpy(char *receiver, const char *sender);

char *_strdup(const char *str);


void _env_variables(char **envp);
size_t _strlen(char *str);

char *_getenv(const char *environ_var);

char *full_path(char *command);




#endif
