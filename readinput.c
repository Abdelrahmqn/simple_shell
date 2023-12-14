#include"main.h"
/**
 * _readinput - Reads input from the command line
 * Description: This function reads the command line input.
 *
 * Return: On success: Pointer to the string. On failure: NULL.
 */

char *_readinput(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;


	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);
}
