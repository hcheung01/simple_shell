#include "lists.h"

char *get_line(void)
{
	char *buf = NULL;
	char *final;
        size_t bufsize = 0;

        while (final = getline(&buf, &bufsize, stdin) != EOF)
	{
	}
	return (final);
}
