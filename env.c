#include "shell.h"

/**
 * env - function to write env
 *
 * Description: print env
 * Return: na
 */
void env(char **env)
{
	int i = 0;
	while (env[i])
	{
		write(1, env[i], _strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
}
