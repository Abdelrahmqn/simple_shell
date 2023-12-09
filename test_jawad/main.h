#ifndef MAIN_H
#define MAIN_H

#define MAX_ARGS 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[], char *envp[]);
int _strcmp(const char *str1, const char *str2);
int _strcpy(char *receiver, const char *sender);

void exec_command(char **argv);



#endif
