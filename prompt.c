#include "lists.h"

int main(void)
{
	int i = 0;
	size_t toksize = 64;
	size_t bufsize = 0;
	char *buf;
	char *token;
	char *toks;
	char **tok = malloc(sizeof(char*) * toksize);

	if (!tok)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	write(1, "$ ", 3);
	getline(&buf, &bufsize, stdin);
	token = strtok(buf, " ");
	printf("token = %s\n", token);
	printf("i before loop = %i\n", i);
	while (token != NULL)
	{
		tok[i] = token;
		printf("TOK BUFFER IS: %s\n", tok[i]);
		token = strtok(NULL, " ");
		i++;
		printf("loop token = %s\n", token);
	}
	tok[i] = NULL;
	return (0);
}
