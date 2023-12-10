#include "main.h"
#include <unistd.h>
#include <sys/wait.h>

void exec_command(char **argv)
{
    pid_t child_pid;
    int status;


    child_pid = fork();
    if (child_pid == 0) {
        execve(argv[0], argv, NULL);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    } else if (child_pid < 0) {
        perror("Error forking");
    } else {
        waitpid(child_pid, &status, 0);
    }
}
