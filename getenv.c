#include "main.h"
/**
 * _getenv - function that reads path environment.
 *
 * @name: write the name of the environment variables.
 *
 * return: NULL, if it fails return (-1).
*/
char *_getenv(const char *name) {
    char **environvar;
    int name_len = _strlen(name);

    for (environvar = environ; *environvar != NULL; environvar++)
	{
		if (_strncmp(name, *environvar, name_len) == 0)
		{
		return (*environvar + name_len + 1);
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
