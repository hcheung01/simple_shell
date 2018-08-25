#include "lists.h"

/**
 * shl_path_buf -  creates a buffer for environ PATH
 * @start: Path as a string
 * Return: array of paths
 */
char **shl_path_buf(char *start)
{
	int i, k;
	int count = 0;
	char **tokens;

	for (k = 0; start[k] != '\0'; k++)
		if (start[k] == ':')
			count++;
	tokens = malloc(sizeof(char *) * (k + 1));
	return (tokens);
}
