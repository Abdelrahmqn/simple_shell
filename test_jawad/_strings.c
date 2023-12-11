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
/**
 * _strcpy - Copies a string from sender to right place!.
 *
 * @receiver: Pointer to the receiver string.
 *
 * @sender: Pointer to the sender string.
 *
 * Return: 0 on success, -1 on failure.
 */

int _strcpy(char *receiver, const char *sender)
{
	int i = 0;

	while (sender[i] != '\0')
	{
		receiver[i] = sender[i];
		i++;
	}
	receiver[i] = '\0';
	return (0);
}
/**
 * _strlen - Calculate the length of a string.
 *
 * @str: The input string whose length to clc.
 *
 * Return: The number of len
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}