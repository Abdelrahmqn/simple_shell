#include "main.h"

/**
 * main - Entry point for the shell program.
 * @argc: Number of arguments passed to program.
 * @argv: Array of strings containing arguments.
 * @envp: Array of strings containing environment variables.
 * Return: 0 on successful execution, -1 on failure.
 */

int main(int argc, char *argv[], char *envp[])
{
	size_t var = 0;
	/* char **args; */
	ssize_t get_command;
	char *command = NULL, *cp_command = NULL;
	char *token;
	int num_of_args = 0;
	int i;

	(void)argc, (void)argv, (void)envp;

	while (1)
	{
		write(1, "$ ", 2);
		get_command = getline(&command, &var, stdin);
		if (get_command == -1)
		{
		perror("exiting the shell\n");
		return (1);
		}
	cp_command = malloc(sizeof(char) * get_command);

	/* check for allocation memory */
	if (cp_command == NULL)
	{
		perror("Allocation Memory Failed");
		return (-1);
	}

	/*copy the command */
	strcpy(cp_command, command);

	/* get the number of argument */

	token = strtok(cp_command, " \n");
	while (token != NULL)
	{
		token = strtok(NULL, " \n");
		num_of_args++;
	}
	num_of_args++;

	/* allocation memory for argv */
	argv = malloc(sizeof(char *) * num_of_args);
	if (argv == NULL)
	{
		perror("Allocation Memory Failed");
		return (-1);
	}

	token = strtok(command, " \n");
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		if (argv[i] == NULL)
		{
			perror("Allocation Memory Failed");
			return (-1);
		}

		strcpy(argv[i], token);
		/* just to check the results  */
		/*printf(" %s \n", argv[i]);*/

		token = strtok(NULL, " \n");
	}

	exec_command(argv);

	}
	free(argv);
	free(cp_command);
	free(command);


	return (0);
}
