#include "main.h"

/**
 * _free1 - free function level 2
 *
 * @variable1: variable level 2.
 *
 * Return: On success: the dest. On failure: NULL.
 */

void _free1(char *variable1)
{
	free(variable1);
	variable1 = NULL;
}

/**
 * _free2 - free function level 2
 *
 * @variable2: variable level 2.
 *
 * Return: On success: the dest. On failure: NULL.
 */
void _free2(char **variable2)
{
	free(variable2);
	variable2 = NULL;
}
/**
 * _free3 - free function level three
 *
 * @variable3: variable level three.
 *
 * Return: On success: the dest. On failure: NULL.
 */
void _free3(char **variable3)
{
	int i;

	if (variable3 == NULL)
		return;
	for (i = 0; variable3[i]; i++)
		_free1(variable3[i]);

	_free2(variable3);
}
