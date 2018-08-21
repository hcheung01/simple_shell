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
void prompt(void)
{
	write(1, "$ ", 3);
}

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

	/** tester to print strings in last buffer */
	while (*tok)
	{
		printf("BUFFER IS %s\n", *tok++);
	}
	printf("You typed: %s\n", *tok);
	return (tok);

}

int main(void)
{
	char *line;
	char **args;
	int i = 0;

	while (i < 1)
	{
		prompt();
		line = get_line();
		args = split_line(line);
		while (*args)
		{
			printf("%s\n", *args);
			*args++;
		}
		printf("%s\n", line);
	}
	return (0);
}

/* void execArg(char *command)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
	} */
