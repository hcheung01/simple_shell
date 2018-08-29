<<<<<<< HEAD
#include "lists.h"
=======
#include "shell.h"
>>>>>>> ee6f3f076279d684066d23ea2cdf3f7cacb1ca41

/**
 * env - function to write env
 *
 * Description: print env
 * Return: na
 */
void env(void)
{
	while (*environ)
	{
		write(1, *environ, _strlen(*environ));
		write(1, "\n", 1);
		environ++;
	}
}
