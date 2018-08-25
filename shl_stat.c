#include "lists.h"

/**
 * shl_stat - takes array of PATHS, appends and stats
 * @tokens: PATH array
 * @getln: shl_getln return
 * @n: str len of getln
 * Return: newer_path - path sent to stat
 */
char *shl_stat(char **tokens, char *getln, int n)
{
	int i = 0;
	int z;
	char *tok, *newpath, *newer_path;

	tok = strtok(start, "PATH=:");
	while (tok != NULL)
	{
		tokens[i] = tok;
		z = strlen(tok);
		new_path = string_nconcat(tokens[i], "/", 1);
		newer_path = string_nconcat(new_path, getln, n);
		if (stat(newer_path, &st) == 0)
		{
			break;
			return (newer_path);
		}
		i++;
		tok = strtok(NULL, "PATH=:");
	}
	tokens[i] = NULL;
	return (0);
}
