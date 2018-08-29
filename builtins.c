#include "lists.h"

/**
 * exitme - function to exit
 * @command: input from cmd
 *
 * Description: exit from shell
 * Return: 0 for success
 */
int exitme(char **command)
{
	if (_strcmp(command[0], "exit") == 0)
		exit(1);
	return (0);
}
/**
 * cd - function to change directory
 * @command: input from cmd
 *
 * Description: change directory
 * Return: 0 for success
 */
int cd(char **command)
{
	chdir(command[1]);
	return (0);
}
/**
 * printenv - function with one argument
 * @command: pointer to cmd
 *
 * Description: print env
 * Return: 0 for success
 */
int printenv(char **command)
{
	int i;

	if (*command)
	{
		i = 0;
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
/**
 * checkBuiltins - function with two arguments
 * @combine: full dir
 * @command: cmd input
 *
 * Description: check for builtins and call function
 * Return: path to builtin or process from dir
 */
int checkBuiltins(char *combine, char **command)
{
	int i;
	char *array[] = {"exit", "cd", "env", NULL};

	typedef int (*Builtins)(char **);
	Builtins functions[] = {&exitme, &cd, &printenv};

	i = 0;
	while (array[i] != NULL)
	{
		if (_strcmp(array[i], command[0]) == 0)
			return (functions[i](command));
		i++;
	}
	return (execute(combine, command));
}
