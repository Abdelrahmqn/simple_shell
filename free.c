#include "main.h"

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
		free(variable3[i]), variable3[i] = NULL;

	free(variable3), variable3 = NULL;
}
