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

char *_getenv(const char *env_var);
char *_getpath(const char *command);





#endif
