#include "lists.h"

char *pathCat(char *dir, char *av)
{
	int i, k, len, len2;
	char *buf;

	len = _strlen(dir);
	len2 = _strlen(av);

	buf = malloc(sizeof(char) * len);

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
        buf[k + 1] = '\0';
	return (buf);
}

char **dirTok(void)/*returns paths without : */
{
        char **tokens;
        char *tok;
	char *fullPath;
	int i;
	char *dir;

	dir = get_env();
	i = 0;
        tokens = malloc(sizeof(char*) * 9);
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
