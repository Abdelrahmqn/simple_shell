#include"main.h"
/**
 * _getenv - the get environment functions.
 *
 * @environ_var: the name of the environment.
 *
 * Return: On success: the dest. On failure: NULL.
 */
char *_getenv(const char *environ_var)
{
	int index = 0;
	char *token;

	while (environ[index])
	{
		token = strtok(environ[index], "=");
		if (strcmp(environ_var, token) == 0)
			return (strtok(NULL, "\n"));
		index++;
	}
	return (NULL);
}


/**
 * full_path - function that call getenv and return full path
 *
 * @command: command line variable.
 *
 * Return: On success: the dest. On failure: NULL.
 */
char *full_path(char *command)
{
	char *path = _getenv("PATH");
	char *token;
	char *full_command = NULL;
	int i = 0;
	struct stat status;

	while (command[i])
	{
		if (command[i] == '/')
		return (command);
		i++;
	}
token = strtok(path, ":");

	while (token)
	{
		full_command = malloc(strlen(command) + strlen(token) + 2);
		if (full_command == NULL)
		{
			perror("Mmeory allocation failed");
			return (NULL);
		}

		strcpy(full_command, token);
		strcat(full_command, "/");
		strcat(full_command, command);

		if (stat(full_command, &status) == 0)
			return (full_command);

		free(full_command);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
