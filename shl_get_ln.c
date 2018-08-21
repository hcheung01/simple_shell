#include "lists.h"

/**
 * shl_get_ln - gets input stores in array
 * Return: nothing
 */
char *shl_get_ln(void)
{
	char *ln = NULL;
	ssize_t bufsize = 0;

	getline(&ln, &buffsize, stdin);/*add test for getline*/
	if (ln == NULL)
		free(ln);
	return (ln);
}
