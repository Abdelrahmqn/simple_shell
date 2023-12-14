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
		if (isatty(STDIN_FILENO) == 1) /* check if the termianl */
			write(1, "$ ", 2);  /* prompt */

		line = _readinput(); /* call the function that take input from user */

		if (line == NULL) /* check the output of the function */
		{
			return (retour_stat); /* return 0 */
		}


		/* if (_strcmp(line, "exit\n") == 0)
		{
			write(1, "Exiting the shell...\n", 22);
			free(line);
			break;
		}
	*/

	cmd = _splitting(line); /* call function that tokenize the line */

	if (cmd == NULL) /* check argv NULL print prompt again */
		continue;

	/* for (i = 0; cmd[i]; i++)  free the array 2D
	{
		printf("%s\n", cmd[i]);
		_free1(cmd[i]);
	} */


	retour_stat = exec_command(cmd, argv, envp);


	_free2(cmd);

	}

	return (0);
}
