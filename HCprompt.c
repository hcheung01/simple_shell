#include "lists.h"

int main(int ac, char **av)
{
	int i = 0;
	size_t toksize = 5;
	size_t basesize = toksize;
	size_t bufsize;
	char *buf;
	char *token;
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
		i++;
		if (i >= toksize)
		{
			toksize += basesize;
			tok = realloc(tok, toksize * sizeof(char*));
			if (!tok)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " ");
		printf("loop token = %s\n", token);
	}
	printf("FINAL TOKEN SIZE IS: %lu\n", toksize);
	tok[i] = NULL;
	printf("FINAL INDEX I IS: %i\n", i);

	while (i > 0)
	{
		printf("\n Pointer String is: %s\n", *tok);
		*tok++;
		i--;
	}

	return (0);
}
