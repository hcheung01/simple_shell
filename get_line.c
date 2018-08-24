#include "lists.h"

char *get_line(void)
{
	char *buf = NULL;
        size_t bufsize = 0;

        getline(&buf, &bufsize, stdin);
	return (buf);
}
