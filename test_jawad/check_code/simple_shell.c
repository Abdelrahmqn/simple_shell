#include"main.h"
#include<stdio.h>

int main()
{
	char *command = NULL;

	command = malloc(10);
 
	for (int i = 0; i < 4; i++)
	{
		write(1, "$ ", 2);
		scanf("%s",command);
		printf("%s\n",_getpath(command));

	}
	free(command);

	return (0);
}
