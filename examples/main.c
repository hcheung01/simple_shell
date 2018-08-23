#include "lists.h"

int main(int ac, char **av, char **ev)
{
	int i, k;
	int len;
	char *start;
	char **tokens;
	char *tok, *buf, *line;
	char *str = "PATH";

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
	i = 0;
	/* Calc length */
	len = strlen(start);

	/* push into buffer */
	buf = malloc(sizeof(char) * len + 1);
	while (start[i] != '\0')
	{
		buf[i] = start[i];
		i++;
	}
	printf("%s\n", buf);

	/* split buf into token of directories */
	tokens = malloc(sizeof(char*) * 8);

	tok = strtok(buf, "PATH=:");
	while (tok != NULL)
	{
		printf("%s\n", tok);
		tokens[i] = tok;
		i++;
		tok = strtok(NULL, "PATH=:");
	}
	tokens[i] = NULL;
	return (0);
}
