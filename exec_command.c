#include "main.h"
/**
 * exec_command - Executes the command received as input.
 *
 * @cmd: commmand line.
 * @envp: the environment variable.
 * @argv: The argument vector containing the command and its arguments.
 *
 * Return: 0 on successful execution, -1 on failure.
 */
int exec_command(char **cmd, char **argv, char **envp)
{
	int stat = 255;
	char *path;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Failed to fork");
		return (-1);
	}
	if (child_pid == 0)
	{
		path = full_path(cmd[0]);
		if (path == NULL)
		{
			perror(argv[0]);
			
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
		waitpid(child_pid, &stat, 0);
		if (WEXITSTATUS(stat))
		{
			return (WEXITSTATUS(stat));
		}
			else
			{
				return (-1);
			}
	}
	return (-1);
}
