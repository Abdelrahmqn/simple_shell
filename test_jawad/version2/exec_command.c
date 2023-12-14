#include "main.h"
/**
 * exec_command - Executes the command received as input.
 *
 * @cmd: the command line.
 * @argv: argument vector.
 * @envp: environment..
 *
 * Return: 0 on successful execution, -1 on failure.
 */
int exec_command(char **cmd, char **argv, char **envp)
{
	pid_t child_pid;
	int status;
	char *path = NULL;
	path = full_path(cmd[0]);
	

	if (path == NULL)
	{
		perror(argv[0]);
		/* _free3(cmd); */
	}
	
	child_pid = fork();
	
	if (child_pid == 0)
	{
		if (execve(path, cmd, envp) == -1)
		{
			free(path);
			_free3(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free(path);
		_free3(cmd);
	}
	

 
	return (WEXITSTATUS(status));
}
