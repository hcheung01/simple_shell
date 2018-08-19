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
	int buf = 64;
	int count = 0;
	char **tok = NULL;
	char *token;
	char *dup_ln = _strdup(*ln);

	token = strtok(ln, " \n\t\r\a");
	while(token)
	{
		
	if (!tok)
	{
		perror("Error: allocation error\n");
		_exit(99);
	}
	while (token != NULL)
	{
		tok[count] = token;
		count++;
		if (count >= buf)
		{
			buf += 64;
			tok = 
