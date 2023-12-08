#include "main.h"
/**
 * _strcmp - Compares two strings.
 *
 * @str1: First string to compare.
 * @str2: Second string to compare.
 *
 * Return: integer less than or equal to etc..
 */

int _strcmp(const char *str1, const char *str2)
{
int i = 0;

while (str1[i] != '\0' && str2[i] != '\0')
{
if (str1[i] != str2[i])
{
return (str1[i] - str2[i]);
}
i++;
}

if (str1[i] == '\0' && str2[i] == '\0')
{
return (0);
}
else if (str1[i] == '\0')
{
return (-1);
}
else
{
return (1);
}
}
