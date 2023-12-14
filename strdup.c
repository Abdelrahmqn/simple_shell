#include "main.h"
/**
 * _strdup - duplicate the string..
 *
 * @str: the string.
 *
 * Return: On success: the dest. On failure: NULL.
 */

char *_strdup(const char *str)
{
size_t index, len = 0;
char *dest;

if (str == NULL)
return (NULL);

while (str[len] != '\0')
{
len++;
}
dest = malloc(sizeof(char) * (len + 1));
if (dest != NULL)
{
for (index = 0; index < len; index++)
{
dest[index] = str[index];
}
dest[len] = '\0';
}
return (dest);
}
