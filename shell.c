#include "shell.h"

/**
 * main - primary function with no args
 *
 * Description: initiate looper function
 * Return: 0 for success
 */
int main(int argc, char **argv, char **env)
{
	if (argc == 1 || argv[1] == NULL)
		looper(env);

	return (0);
}
