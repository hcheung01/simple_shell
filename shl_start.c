#include <lists.h>

/**
 * shl_start - forks tok(args) passed from shl_parse
 * @tok: list of arguments from shl_parse
 * Return: 1
 */
int shl_start(char *args[])
{
	pid_t pid, wpid;
	int state;

	pid = fork();
	if (pid == 0)
		if (execvp(args[0], args) == -1)
			perror("shl");
	_exit(EXIT_FAILURE);
	else if (pid < 0)
		perror("shl");
	else
		while (!WIFEEXITED(state) && !WIFSIGNALED(state));
	return (1);
}
