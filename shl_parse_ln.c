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
}
