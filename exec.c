<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#include "lists.h"
=======
#include "shell.h"
>>>>>>> ee6f3f076279d684066d23ea2cdf3f7cacb1ca41
=======
#include "shell.h"
>>>>>>> a144f34a273863057b5b6f15ac35141129c9b338
=======
#include "shell.h"
>>>>>>> a144f34a273863057b5b6f15ac35141129c9b338

/**
 * execute - function with two arguments
 * @fullPath: full directory with cmd
 * @command: cmd input
 *
 * Description: execute command
 * Return: status
 */
int execute(char *fullPath, char **command)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == 0)
	{
		status = execve(fullPath, command, NULL);
		exit(status);
	}
	else
		wait(NULL);
	return (status);
}
