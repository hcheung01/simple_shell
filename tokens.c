#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * str_token - function with one arguments
 * @str: pointer to string
 * @buffer: buffer from read_line_buff function
 *
 * Description: break apart string arguments into tokens
 * Return: pointer to string
 */
void *str_token(void)
{
	char *token;
	char **buffer;
	char *str;
	int index = 0;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);

	str = "hello you there world";
	token = strtok(str, " ");
	/* loop until last token equals NULL */
	while (token != NULL)
	{
		buffer[index] = token;
		token =  strtok(NULL, " ");
		printf("token is %s", token);
		index++;
	}
	buffer[index] = 0;

	while (*buffer)
	{
		printf("%s\n", *buffer);
	}
	return (buffer);
}


int main(void)
{
	str_token();
	return (0);
}
