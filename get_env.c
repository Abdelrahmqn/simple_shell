#include"main.h"
/**
 * _getenv - function that handles the path.
 * @environ_var: the environment variables.
 *
 * return: NULL on failure.
*/

char *_getenv(const char *environ_var)
{
	int i = 0;
	char *token, *temp, *value, *path;
	size_t var_len = strlen(environ_var);

	for (i = 0; environ[i]; i++)
	{
		temp = strdup(environ[i]);
		token = strtok(temp, "=");

		if (strncmp(token, environ_var, var_len) == 0 && environ[i][var_len] == '=')
		return (strdup(environ[i] + var_len + 1));
		{
			value = strtok(NULL, "\n");
			path = strdup(value);
			free(temp);
			return (path);
		}
	}
	return (NULL);
}

char *get_path(const char *command)
{
	char *path;
	char *token;
	char *sum_path;
	struct stat st;

	if (command[0] == '/')
	{
		if (stat(command, &st) == 0)
		{
			return (strdup(command));
		}
		return (NULL);
	}
	path = _getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	sum_path = NULL;
	token = strtok(path, ":");
	while (token)
	{
	sum_path = malloc(strlen(token) + strlen(command) + 2);
	if (sum_path == NULL)
	{
		free(path);
		return (NULL);
	}
		strcpy(sum_path, token);
		strcat(sum_path, "/");
		strcat(sum_path, command);

		if (stat(sum_path, &st) == 0)
		{
			free(path);
			return (sum_path);
		}
		free(sum_path), token = strtok(NULL, ":");
	}
	free(path), return (NULL);
}
