#include"main.h"

char *_readinput(void)

{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;	


	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
