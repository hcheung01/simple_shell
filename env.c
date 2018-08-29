#include "lists.h"

void env(void)
{
	{
		write(1, *environ, _strlen(*environ));
		write(1, "\n", 1);
		environ++;
	}
}
