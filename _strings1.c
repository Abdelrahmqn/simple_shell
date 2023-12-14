#include "main.h"
/**
 * _strcat - Write a function that concatenates two strings
 * @dest: characters
 * @src: characters
 * Return: when need.
 */
char *_strcat(char *dest, char *src)
{
int i = 0;
int len = 0;

	while (dest[len] != '\0')
	{
		len++;
	}

	while (src[i] != '\0')
	{
	dest[len + i] = src[i];
	i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
