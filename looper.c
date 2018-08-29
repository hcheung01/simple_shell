<<<<<<< HEAD
<<<<<<< HEAD
#include "lists.h"
=======
#include "shell.h"
>>>>>>> ee6f3f076279d684066d23ea2cdf3f7cacb1ca41
=======
#include "shell.h"
>>>>>>> a144f34a273863057b5b6f15ac35141129c9b338

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
