#include "lists.h"

/**
 * looper - function with no arguments
 *
 * Description: main loop to initiate shell
 * Return: na
 */
void looper(void)
{
	char *line;
	char **dir, **command;
	char *combine;

	while (1)
	{
		prompt();
		line = get_line();
		command = split_line(line);
		dir = dirTok();
		combine = checkPath(dir, command[0]);
		checkBuiltins(combine, command);
	}
	free(line);
	free(command);
	free(dir);
	free(combine);
}
