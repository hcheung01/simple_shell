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
	size_t bufsize = 1024;
	char *buf;
	char *dup_buf;
	char *token;
	char *toks;
	char **tok = NULL;
	/*size_t characters;*/
	int i = 1;

	buf = malloc(bufsize * sizeof(char));
	if (buf == NULL)
		return (1);
	write(1, "$ ", 3);
	getline(&buf, &bufsize, stdin);
	dup_buf = _strdup(buf);
	printf("%s\n", dup_buf);
	token = strtok(buf, " \n");
	printf("token = %s\n", token);
	printf("i before loop = %i\n", i);
	while (token)
	{
		token = strtok(NULL, " ");
		i++;
		printf("loop token = %s\n", token);
	}
	printf("after loop i = %i\n", i);
	*tok = malloc(sizeof(char*) * i);
	printf("XXXXXXX");
	if (*tok == NULL)
		return (1);
	printf("*tok created %i * 8 bytes", i);
	toks = strtok(dup_buf, " ");
	tok[i] = NULL;
	i = 0;
	printf("%i = 0\n", i);
	while (tok != '\0')
	{
		tok[i] = toks;
		toks = strtok(NULL, " ");
		i++;
	}
	/*printf("%lu characters were read.\n", characters);*/
	printf("You typed: %s\n", *tok);
	return (0);
}
