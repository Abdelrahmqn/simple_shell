#include "main.h"
/**
 * exec_command - Executes the command received as input.
 *
 *
 * @argv: The argument vector containing the command and its arguments.
 *
 * Return: 0 on successful execution, -1 on failure.
 */
int exec_command(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error excuting command\n");
			return(-1);
		}
	}
	else if (child_pid > 0)
	{
		waitpid(child_pid, &status, 0);
	}
	else
	{
		perror("failed to fork");
		return (-1);
	}
	return (0);
}
/**
 * _spliting - Function that tokenizes the command line arguments.
 * @input_command: command to be tokenized.
 * @argv: the command line arguments.
 * Return: number of arguments.
 */
int _spliting(char *input_command, char **argv)
{
	int num_of_args = 0;
	char *to_tokenize;

	to_tokenize = strtok(input_command, " \n");
	while (to_tokenize != NULL && num_of_args < LIM_ARGS - 1)
	{
		argv[num_of_args] = to_tokenize;
		to_tokenize = strtok(NULL, " \n");
		num_of_args++;
	}
	argv[num_of_args] = NULL;

	if (num_of_args == 0)
		return (-1);

	return (num_of_args);
}
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
	ssize_t get_command;
	char *command;
	int no_of_argument;
	/*int i;*/
	(void)argc;
	(void)envp;

	while (1)
	{
		write(1, "$ ", 2);
		command = NULL;
		get_command = getline(&command, &var, stdin);
		if (get_command == -1)
		{
			free(command);
			perror("exiting the shell\n");
			return (1);
		}

		if (_strcmp(command, "exit\n") == 0)
		{
			write(1, "Exiting the shell...\n", 22);
			free(command);
			break;
		}

	no_of_argument = _spliting(command, argv);

	if (no_of_argument != -1) 
	{
		if (exec_command(argv) == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
	}	

	/*for (i = 0; i < no_of_argument-1; i++)
	
		free(argv[i]);
	*/

	free(command);
	
	}
	return (0);
}
