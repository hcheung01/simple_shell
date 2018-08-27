#include <sys/stat.h>
#include "lists.h"

char *pathCat(char *dir, char *av)
{
	int i, k, len, len2;
	char *buf;

	len = strlen(dir);
	len2 = strlen(av);

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

int main(int ac, char **av, char **ev)
{
	pid_t child;
        int i, k, dircount = 2;
        int len;
        char *start;
        char **tokens;
        char *tok, *buf, *str = "PATH";
	char *fullPath;
	struct stat st;

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
        len = strlen(start);
        buf = malloc(sizeof(char) * len + 1 + 8);

	i = 5;
	k = 0;
        while (start[i] != '\0')
        {
		if (start[i] == ':')
		{
			buf[k] = '/';
			k++;
			dircount++;
		}
                buf[k] = start[i];
                i++;
		k++;
        }
	buf[k] = '/';

	i = 0;
        tokens = malloc(sizeof(char*) * dircount);
        tok = strtok(buf, " :");
        while (tok != NULL)
        {
                tokens[i] = tok;
                i++;
                tok = strtok(NULL, " :");
        }
	tokens[i] = NULL;

	while(*tokens != NULL)
	{
		fullPath = pathCat(*tokens, av[1]);
		if (stat(fullPath, &st) == 0)
		{
			child = fork();
			if (child == 0)
			{
				execve(fullPath, av, NULL);
			}
		}
		else
			printf("NOT FOUND\n");
		*tokens++;
	}

	return (0);
}
