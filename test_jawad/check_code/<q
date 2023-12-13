#include"main.h"
#include<stdio.h>

int main(int argc, char **argv)
{
	char *full_cmd;

	(void)argc;

	full_cmd = _getpath(argv[1]);

	if (full_cmd)
		printf("%s\n",full_cmd);
	else
		printf("command not exist");

	free(full_cmd);



	return (0);
}
