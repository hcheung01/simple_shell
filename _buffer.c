#include "lists.h"
#define BUFSIZE 1024

/**
 * read_line_buff - function with no arguments
 *
 * Description: read input argument from command line and push into buffer
 * Return: pointer to buffer
 */
char *read_line_buff(void)
{
	int bufsize = BUFSIZE;
	int index = 0;
	int get;
	char *buffer;

	/* create buffer of bufsize */
	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	/* loop over line and push each char to buffer */
	while (1)
	{
		/* read character */
		get = getchar();
		/* if EOD, replace with null and return */
		if (c == EOF || c == '\n')
		{
			buffer[index] = '\0';
			return (buffer);
		}
		else
		{
			/* push chars to buffer until uncle Damon say stop*/
			buffer[index] = c;
		}
		index++;
	}

	/* reallocate more memory block if needed */
	if (position >= bufsize)
	{
		bufsize += BUFSIZE;
		buffer = realloc(buffer, bufsize);
		if (buffer == NULL)
		{
			fprintf(stderr, "allocation error\n");
			exit(EXIT_FAILURE);
		}
	}
}
