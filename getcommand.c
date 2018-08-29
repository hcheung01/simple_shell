#include "shell.h"

/**
 * get_line - function with no args
 *
 * Description: get line from cmd
 * Return: buffer
 */
char *get_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;
	int test;

	test = getline(&buf, &bufsize, stdin);
	if (test == EOF)
	{
		write(1, "\n", 1);
		_exit(1);
	}
	return (buf);
}

/**
 * split_line - function with one argument
 * @line: cmd input
 *
 * Description: split line into tokens
 * Return: tokens
 */
char **split_line(char *line)
{
	char *dup_buf;
	char *token;
	char *toks;
	char **tok;
	int i = 1;

	dup_buf = _strdup(line);
	token = strtok(line, DELIM);
	while (token)
	{
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line);
	tok = malloc(sizeof(char *) * i + 1);
	toks = strtok(dup_buf, DELIM);
	i = 0;
	while (toks)
	{
		tok[i] = toks;
		toks = strtok(NULL, DELIM);
		i++;
	}
	tok[i] = '\0';
	return (tok);
}
