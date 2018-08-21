#include "lists.h"

#DEFINE DELIM "\n\t\r\a"
#DEFINE TOKSIZE 64

/**
 * shl_parse_ln - breaks user input into tokens
 * @ln: string to be broken into tokens
 * Return: tokens or tok
 */
char **shl_parse_ln(char *line)
{
<<<<<<< HEAD
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
=======
	int i = 0;
	size_t buffsize = 1024;
	char *tokens;
	char *token;
	char *dup_ln = _strdup(line);

	/* create buffer to store pointers to tokens */
	tokens = malloc(sizeof(char*) * ptrcount + 1);
	if (tokens == NULL)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while(token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	token[i] = NULL;

	if (!tok)
	{
		perror("Error: allocation error\n");
		_exit(99);
	}
	return (tokens);
>>>>>>> 7666add1a60d0dd011c48796e40c222f1f4999e1
}
