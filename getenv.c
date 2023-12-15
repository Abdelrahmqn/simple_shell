#include "main.h"
/**
 * _getenv - calling environ pointer
 *
 * @name: the name of the variables owner.
 *
 * Return: NULL at the end of the function.
 */

char *_getenv(const char *name)
{
	char **environ_var;
	int name_len = _strlen(name);

	for (environ_var = environ; *environ_var != NULL;)
	{
		environ_var++;
		if (_strncmp(name, *environ_var, name_len) == 0)
		{
			return (*environ_var + name_len + 1);
		}
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
	struct stat status;
	int i = 0;

		while (command[i])
	{
		if (command[i] == '/')
		return (command);
		i++;
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		full_command = malloc(strlen(command) + strlen(token) + 2);
		if (full_command == NULL)
		{
			perror("Mmeory allocation failed");
			return (NULL);
		}

		_strcpy(full_command, token);
		_strcat(full_command, "/");
		_strcat(full_command, command);

		if (stat(full_command, &status) == 0)
		{
			return (full_command);
		}

		free(full_command);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
