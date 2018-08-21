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
	size_t bufsize;
	char *dup_buf;
	char *token;
	char *toks;
	char **tok;
	int i = 1;
	char *buf = NULL;

	write(1, "$ ", 3);
	getline(&buf, &bufsize, stdin);
	dup_buf = _strdup(buf);
	printf("%s\n", dup_buf);
	token = strtok(buf, " \n\t\r\a");
	printf("token = %s\n", token);
	printf("i before loop = %i\n", i);
	while (token)
	{
		token = strtok(NULL, " \n\t\r\a");
		i++;
		printf("loop token = %s\n", token);
	}
	free(buf);
	printf("i after loop i = %i\n", i);
	tok = malloc(sizeof(char *) * i);
	printf("XXX");
	/*if (tok == NULL)
	  return (1);*/
	printf("*tok created %i * 8 bytes\n", i);
	toks = strtok(dup_buf, " \n\t\r\a");
	tok[i - 1] = '\0';
	i = 0;
	printf("%i = 0\n", i);
	while (toks)
	{
		tok[i] = toks;
		toks = strtok(NULL, " \n\t\r\a");
		i++;
	}
	printf("You typed: %s\n", *tok);
	return (0);
}
