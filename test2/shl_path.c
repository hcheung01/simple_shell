#include "lists.h"

/**
 * shl_path - find the PATH in environ
 *
 * Return: start PATH as a string
 */

char *shl_path(void)
{
	int i, k;/*loop vars*/
	char *start;/*full PATH found in first loop*/
	static char **environ;
	char *str = "PATH";

	i = 0;
	while (environ[i])
	{
		k = 0;
		while (environ[i][k] == str[k])
		{
			if (environ[i][k + 1] == str[k + 1])
			{
				start = environ[i];
				break;
			}
			k++;
		}
		i++;
	}
	return (start);
}
