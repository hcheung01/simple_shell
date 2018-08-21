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

#define DELIM " \n\t\r\a"
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
			printf("THIS LAST TEST FROM THE MAIN() TO PRINT ARGS: %s\n", *args);
			*args++;
		}
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
