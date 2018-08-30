#include "shell.h"

/**
 * looper - function with no arguments
 *
 * Description: main loop to initiate shell
 * Return: na
 */
void looper(char **env)
{
	char *line;
	char **dir, **command;
	char *combine;

	while (1)
	{
		prompt();
		line = get_line();
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		command = split_line(line);
		dir = dirTok(env);
		combine = checkPath(dir, command[0]);
		checkBuiltins(combine, command);
	}
	free(line);
	free(command);
	free(dir);
	free(combine);
}
