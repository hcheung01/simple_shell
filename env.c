#include "lists.h"

void env(void)
{
<<<<<<< HEAD
	while (*environ)
	{
		write(1, *environ, _strlen(*environ));
		write(1, "\n", 1);
		*environ++;
=======
        while (*environ)
	{
		write(1, *environ, _strlen(*environ));
		write(1, "\n", 1);
		environ++;
>>>>>>> a28552acb775acbb0d0ce0d7510e7de30d4f0c0e
	}
}
