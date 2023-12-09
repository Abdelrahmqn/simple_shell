#include "main.h"

void exec_command( char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror ("Error excuting command ");
		}
	}
}

