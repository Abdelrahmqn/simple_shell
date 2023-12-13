#include"main.h"
/**
 * _getenv - function that handles the path.
 * @environ_var: the environment variables.
 *
 * return: NULL on failure.
*/

char *_getenv(const char *environ_var)
{
	/*extern char **environ;*/
	int i = 0;
	char *token, *temp, *value, *path;

	for (i = 0; environ[i]; i++)
	{
		temp = strdup(environ[i]);
		token = strtok(temp, "=");

		if (strcmp(token, environ_var) == 0)
		{
			value = strtok(NULL, "\n");
			path = strdup(value);
			free(temp);
			return (path);
		}
	free(temp);
	}
	return (NULL);
}

char *get_path(const char *command)
{
	char *path;
	char *token;
	char *sum_path;
	struct stat st;

	path = _getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	token = strtok(path, ":");
	while (token)
	{
		sum_path = NULL;
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

		sum_path = NULL;
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
