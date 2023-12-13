#include"main.h"

char *_getenv(const char *environ_var)
{
	extern char **environ;
	int index = 0;
	char *token;

	while (environ[index])
	{
		token = strtok(environ[index],"=");
		if (strcmp(environ_var, token) == 0)
			return (strtok(NULL, "\n"));
		index++;
	}
	return (NULL);
}


char *full_path(char *command)
{
	char *path = _getenv("PATH");
	char *token;
	char *full_command = NULL;
	struct stat status;

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
