#include"main.h"

/**
 * _splitting - Function that tokenizes the command line arguments.
 * @line: the line to be spilted.
 * Return: an array of command
 */
char **_splitting(char *line)
{
	int num_args = 0, i = 0;
	char *token = NULL, *line_dup = NULL;
	char **line_command = NULL;

	if (line == NULL)
	return (NULL);

	line_dup = _strdup(line);
	token = strtok(line_dup, DELIM);
	if (token == NULL)
	{
	free(line_dup), line_dup = NULL;
	free(line), line = NULL;
	return (NULL);
	}

	while (token != NULL)
	{
		num_args++;
		token = strtok(NULL, DELIM);
	}
	free(line_dup), line_dup = NULL;
	line_command = malloc(sizeof(char *) * (num_args + 1));

	if (line_command == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token != NULL && num_args < LIM_ARGS - 1)
	{
		line_command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	line_command[num_args] = NULL;
	free(line), line = NULL;
	return (line_command);
}

