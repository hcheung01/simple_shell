#include "lists.h"

char *get_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;
	getline(&buf, &bufsize, stdin);
	return (buf);
}

char **split_line(char *line)
{
	size_t bufsize;
	char *dup_buf;
	char *token;
	char *toks;
	char **tok;
	int i = 1;
	char *buf = NULL;
	dup_buf = _strdup(line);
	token = strtok(line, DELIM);
	while (token)
	{
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line);
	tok = malloc(sizeof(char *) * i);
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
