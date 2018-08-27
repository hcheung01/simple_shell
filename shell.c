#include "lists.h"

char *checkPath(char *dir, char *command)
{
	struct stat st;
	char *fullPath;

	if (!command || !dir)
		return (NULL);

	while (dir)
	{
		fullPath = pathCat(dir, command);
		if (!fullPath)
			return (NULL);
		if (stat(fullPath, &st) == 0)
	        	return (fullPath);
		free(fullPath);
	        dir++;
	}
	return (NULL);
}

int execute(char *fullPath, char **command)
{
	pid_t child;

	child = fork();
	if (child == 0)
	{
		execve(fullPath, command, NULL);
	}
	else if (child == -1)
	{
		perror("Error: failed fork");
		exit(99);
	}
	else
		wait(NULL);
	return (1);
}


int main(void)
{
	char *line;
	char **dir, **command;
	int i = 0;
	char *combine;
	pid_t child;


	while (i < 1)
	{
		prompt();
		line = get_line();
		command = split_line(line);
		dir = dirTok();
		combine = checkPath(*dir, command[0]);
		execute(combine, command);

	}
	return (0);
}
