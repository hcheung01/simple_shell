#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

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
	write(1, "% ", 3);
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
	/*size_t bufsize;*/
	char *dup_buf;
	char *token;
	char *toks;
	char **tok;
	int i = 1;
	/*char *buf = NULL;*/

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
/*
int launchme(char **command)
{
	pid_t wait;
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			perror("error return from exec");
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("error pid is less than 0");
	}
	else
	{
		wait(&status);
		printf("THIS PID IS WORKING\n");
	}
	return (1);
}

int execArg(char **tok)
{
	int i;
        char *argv[] = {"cd", "man", "exit", NULL};

	for(i = 0; tok[i] != NULL; i++)
	{
		if (_strcmp(tok[0], argv[i]))
		{
			printf("FOUND COMMAND: %s\n", tok[i]);
			return (1);
		}
	}
        return (launchme(tok));
}
*/
int main(void)
{
	char *line;
	char **args;
	pid_t child_pid;
	/* args = {"cd", "man", "exit", NULL}; */
	/*int i = 0;*/
	/*int exec;*/

	while (1)
	{
		prompt();
		line = get_line();
		if (line[0] == '\n')
			continue;
		args = split_line(line);
		printf("%s", args[0]);
/*		while (args[i])
		{
			printf("THIS LAST TEST FROM THE MAIN() TO PRINT \
ARGS: %s\n", args[i]);
			i++;
		}
		if (execve(args[0], args, NULL) == -1)
		{
			printf("StrCmp found args and returned to main\n");
		}
*/

		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("error return from exec");
			}
		}
		else if (child_pid < 0)
		{
			perror("error pid is less than 0");
		}
		else
		{
			wait(NULL);
			printf("THIS PID IS WORKING\n");
		}
	}
	return (0);
}
