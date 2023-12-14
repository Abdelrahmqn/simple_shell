#include "main.h"


/**
 * main - Entry point for the shell program.
 * @argc: Number of arguments passed to program.
 * @argv: Array of strings containing arguments.
 * @envp: Array of strings containing environment variables.
 * Return: 0 on successful execution, -1 on failure.
 */

int main(int argc, char **argv, char **envp)
{
	int retour_stat = 0;
	char *line = NULL;
	char **cmd = NULL;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);

		line = _readinput();

		if (line == NULL)
		{
			return (retour_stat);
		}
	cmd = _splitting(line);

	if (cmd == NULL)
		continue;


	retour_stat = exec_command(cmd, argv, envp);
	
	_free3(cmd);

	}
	return (0);
}
