#include "lists.h"

char *checkPath(char **dir, char *command)
{
	struct stat st;
	char *fullPath;
	int i;

	if (stat(command, &st) == 0)
	{
		return (command);
	}

	i = 0;
	while (*dir)
	{
		fullPath = pathCat(*dir, command);
		if (stat(fullPath, &st) == 0)
			return (fullPath);
		*dir++;
	}
	return (NULL);
}

int execute(char *fullPath, char **command)
{
	pid_t child;
	int status;

	child = fork();
        if (child == 0)
        {
                status = execve(fullPath, command, NULL);
        }
	else
		wait(NULL);
	return (status);
}


void looper(void)
{
	char *line;
	char **dir, **command;
	int status = 1;
	char *combine;
	int exec;
	pid_t child;

	while (1)
	{
		prompt();
		line = get_line();
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		command = split_line(line);
		dir = dirTok();
		combine = checkPath(dir, command[0]);
		execute(combine, command);
	}
}

int main(int ac, char **av, char **ev)
{

	looper();
	return(0);
}
