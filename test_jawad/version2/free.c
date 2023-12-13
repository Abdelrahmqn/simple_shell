#include "main.h"


void _free1(char *variable1)
{
	free(variable1);
	variable1 = NULL;
}

void _free2(char **variable2)
{
	free(variable2);
	variable2 = NULL;
}
