#include "lists.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to be duplicated
 * Return: duplcate string or NULL
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
 * shl_parse_ln - breaks user input into tokens
 * @ln: string to be broken into tokens
 * Return: tokens or tok
 */
char **shl_parse_ln(char *ln)
{
	int count = 0;
	char **tok = NULL;
	char *token, *token2;
	char *dup_ln = _strdup(ln);

	token = strtok(ln, " \n\t\r\a");
	while (token)
	{
		token = strtok(NULL, " \n\t\r\a");
		count++;
	}
	free(ln);
	tok = malloc(sizeof(char *) * count);
	token2 = strtok(dup_ln, " \n\t\r\a");
	tok[count - 1] = '\0';
	count = 0;
	while (token2)
	{
		tok[count] = token2;
		token2 = strtok(NULL, " \n\t\r\a");
		count++;
	}
	return (**tok);
}
