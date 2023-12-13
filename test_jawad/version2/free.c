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


void _free3(char **variable3)
{
	int i;
	if (variable3 == NULL)
		return;
	for (i = 0; variable3[i]; i++)
		_free1(variable3[i]);
		
	_free2(variable3);
}
