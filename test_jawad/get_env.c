#include"main.h"


char *_getenv(const char *environ_var)
{
	/*extern char **environ;*/
	int index = 0;
	char *token, *tmp, *value, *path;

	for (index = 0; environ[index]; index++)
	{
		tmp = strdup(environ[index]);
		token = strtok(tmp, "=");

		if (strcmp(token, environ_var) == 0)
		{
			value = strtok(NULL, "\n");
			path = strdup(value);
			free(tmp);
			return (path);
		}
		free(tmp), tmp = NULL;
	}
	free(tmp);
	return (NULL);
}

char *_getpath(const char *command)
{
	char *path;
	char *token;
	char *cmd_full = NULL;
	struct stat st;

	path = _getenv("PATH");

	token = strtok(path, ":");


	while (token)
	{
		cmd_full = malloc(strlen(token) + strlen(command) + 2);

		strcpy(cmd_full, token);
		strcat(cmd_full, "/");
		strcat(cmd_full, command);

		if (stat(cmd_full, &st) == 0)
		{
			free(path);
			return (cmd_full);
		}
		free(cmd_full), cmd_full = NULL;
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);

}
