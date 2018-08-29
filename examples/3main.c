#include "lists.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int _strlen(char *s)
{
	unsigned int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * *_strcpy - copies the string pointed to by src
 * @dest: char
 * @src: char
 *
 * Return: char
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != 0; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *cat;
	unsigned int  s1len, s2len, s1ands2, i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	s1ands2 = _strlen(s1) + _strlen(s2);
	s1len = _strlen(s1);
	s2len = _strlen(s2);

	if (n < s2len)
	{
		cat = malloc(sizeof(char) * (s1len) + n + 1);
		if (cat == NULL)
			return (NULL);
		_strcpy(cat, s1);
		for (i = 0; i < n; i++)
			cat[s1len++] = s2[i];
	}
	else
	{
		cat = malloc(sizeof(char) * (s1ands2) + 1);
		if (cat == NULL)
			return (NULL);
		_strcpy(cat, s1);
		for (i = 0; s2[i] != '\0'; i++)
			cat[s1len++] = s2[i];
	}
	cat[s1len++] = '\0';
	return (cat);
}

int main(int ac, char **av, char **ev)
{
	int i, k;/*loop vars*/
	int len;/*strlen var*/
	char *start;/*full PATH found in first loop*/
	char **tokens;/*buffer for PATHs*/
	char **testtokens = NULL;
	char *tok/*, *buf, *line*/;
	char *str = "PATH";
	int count = 0;
<<<<<<< HEAD
	int z, ex;
	char *new_path, *newer_path;
	struct stat st;
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
=======
	int z;
	char *new_path;
>>>>>>> 579ab08cf75b54714d1730c0816341e199033e89

	/* SCAN FOR PATH POINTER */
	i = 0;
	while (ev[i])
	{
		printf("%s\n", ev[i]);
		k = 0;
		while (ev[i][k] == str[k])
		{
			if (ev[i][k + 1] == str[k + 1])
			{
				start = ev[i];
				break;
			}
			k++;
		}
		i++;
	}

	/*finds all ':' in start for malloc size*/
	printf("i before reset = %i\n", i);
	i = 0;
	for (k = 0; start[k] != '\0'; k++)
		if (start[k] == ':')
			count++;
	printf("count = %i\n", count);
<<<<<<< HEAD

/*	len = strlen(start);*/
=======
	/* Calc length */
/*len = strlen(start);*/
>>>>>>> 579ab08cf75b54714d1730c0816341e199033e89

	/* push into buffer */
/*buf = malloc(sizeof(char) * len + 1);
  while (start[i] != '\0')
  {
  buf[i] = start[i];
  i++;
  }
  printf("TT i = %i\n", i);
  printf("XX%s\n", buf);*/

	/* split buf into token of directories */
	tokens = malloc(sizeof(char*) * (k + 1));

	tok = strtok(start, "PATH=:");
	while (tok != NULL)
	{
		printf("start works - ZZ%s\n", tok);
		tokens[i] = tok;
		z = strlen(tok);
		printf("z = %i\n", z);
		new_path = string_nconcat(tokens[i], "/", 1);
		printf("New path = %s\n", new_path);
<<<<<<< HEAD
		newer_path = string_nconcat(new_path, av[1], 2);
		if (stat(newer_path, &st) == 0)
		{
			printf(" FOUND\n");
			printf("This is the file %s\n", newer_path);
			break;
			return (0);
		}
		printf("new PATH = %s\n", newer_path);
=======
>>>>>>> 579ab08cf75b54714d1730c0816341e199033e89
		i++;
		tok = strtok(NULL, "PATH=:");
	}
	printf("i = %i\n", i);
	tokens[i] = NULL;
	printf("tokens[0] = %s\n", tokens[0]);
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
			return (1);
	}
	if (pid == 0)
	{
		ex = execve(newer_path, argv, NULL);
		if(ex == -1)
			perror("Error:");
		exit(ex);
		printf("hello - %i\n", ex);
	}
	else
	{
		printf("hello");
		wait(NULL);
	}

<<<<<<< HEAD
=======
	while (new_path)
	{
		printf("FINAL BUFFER DIR TOK IS: %s\n", new_path++);
	}

>>>>>>> 579ab08cf75b54714d1730c0816341e199033e89
	return (0);
}