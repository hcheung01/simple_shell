#include "lists.h"

int main(void)
{
	char *line;
	char **args, **args2;
	int i = 0;
	int exec;
	char *combine;
	pid_t child;
	struct stat st;

	while (i < 1)
	{
		prompt();
		line = get_line();
		args = split_line(line);
		args2 = dirTok();
		while (*args2)
		{
			combine = pathCat(*args2, args[0]);
			if (stat(combine, &st) == 0)
			{
				args[0] = combine;
				break;
			}
			*args2++;
		}
		child = fork();
		if (child == 0)
		{
			execve(args[0], args, NULL);
		}
		else
			wait(NULL);
	}
	return (0);
}
