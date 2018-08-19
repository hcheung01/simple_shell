#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
int main(void)
{
	int i = 1;
	size_t bufsize = 1024;
	size_t toksize = 64;
	char *buf;
	char *dup_buf;
	char *token;
	char *toks;
	char **tok = malloc(sizeof(char*) * toksize);

	if (!tok)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	buf = malloc(bufsize * sizeof(char));
	if (buf == NULL)
		return (1);
	write(1, "$ ", 3);
	getline(&buf, &bufsize, stdin);
	dup_buf = _strdup(buf);
	printf("%s\n", dup_buf);
	token = strtok(buf, " ");
	printf("token = %s\n", token);
	printf("i before loop = %i\n", i);
	while (token != NULL)
	{
		tok[i] = token;
		printf("TOK BUFFER IS: %s\n", *tok);
		token = strtok(NULL, " ");
		i++;
		printf("loop token = %s\n", token);
	}
	tok[i] = NULL;
	printf("You typed: %s\n", *tok);
	return (0);
}
