#include "shell.h"

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
