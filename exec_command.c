#include "main.h"
/**
 * exec_command - Executes the command received as input.
 *
 * @cmd: comad line
 * @argv: The argument vector containing the command and its arguments.
 * @envp: environ variable
 * Return: 0 on successful execution, -1 on failure.
 */
int exec_command(char **cmd, char **argv, char **envp)
{
	pid_t child_pid;
	int status, char *path, (void)argv;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Failed to fork"), return (-1);
	}
	if (child_pid == 0)
	{
		path = full_path(cmd[0]);
		if (path == NULL)
		{
			perror("FULL RESOLUTION FAILED");
			exit(EXIT_FAILURE);
		}
			if (execve(path, cmd, envp) == -1)
			{
				perror("EXECUTION FAILED");
				exit(EXIT_FAILURE);
			}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WEXITSTATUS(status))
			return (WEXITSTATUS(status));
	}
	return (-1);
}
