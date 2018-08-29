#include "shell.h"

/**
 * strcmp - function with two arguments
 * @s1: first string argument
 * @s2: second string argument
 *
 * Description: compare two string for identical
 * Return: 0 for success
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _strdup - function to duplicate string
 * @str - string input
 *
 * Description: duplication string
 * Return: buffer to du string
 */
char *_strdup(char *str)
{
	char *dup = NULL;
	int i;
	int k = 0;

	if (str == NULL)
		return (NULL);
	for (k = 0; str[k] != '\0'; k++)
		;
	dup = malloc(sizeof(char) * k + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= k; i++)
		dup[i] = str[i];
	return (dup);
}

/**
 * _strlen - function with 1 argument
 * @s: char type pointer
 *
 * Description: strlen similiar function to return length
 * Return: string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
