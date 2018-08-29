#include "lists.h"

/**
 * pathCat - function with 2 arguments
 * @dir: directory
 * @av: argument value
 *
 * Description: catenate directory to cmd
 * Return: buffer to directory
 */
char *pathCat(char *dir, char *av)
{
	int i, k, len, len2;
	char *buf;

	len = _strlen(dir);
	len2 = _strlen(av);

	buf = malloc(sizeof(char) * len + len2 + 1);

	i = 0;
	while (i < len)
	{
		buf[i] = dir[i];
		i++;
	}
	k = 0;
	while (i < len + len2)
	{
		buf[i] = av[k];
		i++;
		k++;
	}
	buf[i] = '\0';
	return (buf);
}

/**
 * get_env - function with no args
 *
 * Description: get environment variables
 * Return: tokens
 */
char *get_env(void)
{
	int i, k, len;
	char *str = "PATH";
	char *start, *buf;

	i = 0;
	while (environ[i])
	{
		k = 0;
		while (environ[i][k] == str[k])
		{
			if (environ[i][k + 1] == str[k + 1])
			{
				start = environ[i];
				break;
			}
			k++;
		}
		i++;
	}
	len = _strlen(start);
	buf = malloc(sizeof(char) * len + 1 + 8);

	i = 5;
	k = 0;
	while (start[i] != '\0')
	{
		if (start[i] == ':')
		{
			buf[k] = '/';
			k++;
		}
		buf[k] = start[i];
		i++;
		k++;
	}
	buf[k] = '/';
	k++;
	buf[k] = '\0';
	return (buf);
}

/**
 * dirTok - function with no arguments
 *
 * Description: Split directories to tokens
 * Return: buffer
 */
char **dirTok(void)
{
	char **tokens;
	char *tok;
	int i;
	char *dir;

	dir = get_env();
	i = 0;
	tokens = malloc(sizeof(char *) * 9);
	tok = strtok(dir, " :");
	while (tok != NULL)
	{
		tokens[i] = tok;
		i++;
		tok = strtok(NULL, " :");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * checkPath - function with 2 arguments
 * @dir: dirctory tokens
 * @command: cmd input
 *
 * Description: check path
 * Return: full path or 0
 */
char *checkPath(char **dir, char *command)
{
	struct stat st;
	char *fullPath;

	if (stat(command, &st) == 0)
	{
		return (command);
	}
	while (*dir)
	{
		fullPath = pathCat(*dir, command);
		if (stat(fullPath, &st) == 0)
			return (fullPath);
		dir++;
	}
	perror(command);
	return (NULL);
}
