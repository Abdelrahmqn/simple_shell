#include "main.h"
/**
 * exec_command - Executes the command received as input.
 *
 *
 * @argv: The argument vector containing the command and its arguments.
 *
 * Return: 0 on successful execution, -1 on failure.
 */
int exec_command(char **cmd, char **argv, char **envp)
{
	
	pid_t child_pid;
	int status;
	char *path;

	child_pid = fork();

	if (child_pid == 0)
	{
		path = full_path(cmd[0]);
		if (path == NULL)
		{
			perror("path null");
			/* _free2(cmd); */
			exit(0);
		}
		else
		{
			if (execve(path, cmd, envp) == -1)
			{
				perror(argv[0]);
				exit(0);
			}
		}
	}
	else if (child_pid > 0)
	{
		waitpid(child_pid, &status, 0);
		/* _free2(cmd); */
	}
	else
	{
		perror("failed to fork");
		/* _free2(cmd); */
		exit(0);
	}
	return (WEXITSTATUS(status));
}
