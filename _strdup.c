#include "main.h"
/**
 * _strdup - function that duplicates a string
 *
 * @str: the string that will be duplicated.
 *
 * return: the length of string.
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