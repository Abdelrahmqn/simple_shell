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
	char **args;
	ssize_t get_command;
	char *command = NULL, *cp_gcommand = NULL;
	char *token;
	int num_of_args;

	(void)argc, (void)argv;

	while (1)
	{
		write(1, "$ ", 2);
		get_command = getline(&command, &var, stdin);
		if (get_command == -1)
		{
		perror("exiting the shell\n");
		return (1);
		}
	cp_gcommand = malloc(sizeof(char) * get_command);
	(void)cp_gcommand;
	token = strtok(command, " \n");
	while (token != NULL)
	{
		token = strtok(NULL, " \n");
		num_of_args++;
	}
	num_of_args++;

	free(command);
	exec_command(argv);
	}
	return (0);
}
