#include "lists.h"

/**
 * shl_loop - reads input. Parses. Executes.
 * Return: nothing
 */
void shl_loop(void)
{
	char *ln;
	char **args;
	int loop;

	do {
		write(1, "$ ", 3); /*have to use write*/
	/*work on proper loop while loop instead of do/while*/
		ln = shl_get_ln();
		args = shl_parse_ln(ln);
		loop = shl_exe(args);

		free(ln);
		free(args);
	} while (loop);
}
