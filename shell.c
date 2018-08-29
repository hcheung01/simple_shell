#include "lists.h"

char *checkPath(char **dir, char *command)
{
	struct stat st;
	char *fullPath;

	if (stat(command, &st) == 0)
	{
		return (command);
	}

	while (*dir)
	{
		fullPath = pathCat(*dir, command);
		if (stat(fullPath, &st) == 0)
			return (fullPath);
		dir++;
	}
	return (NULL);
}

int execute(char *fullPath, char **command)
{
	pid_t child;
	int status = 0;

	child = fork();
        if (child == 0)
        {
                status = execve(fullPath, command, NULL);
		exit(status);
        }
	else
		wait(NULL);
	return (status);
}

int exitme(char **command)
{
	if (_strcmp(command[0], "exit") == 0)
		exit(1);
	return (0);
}

int cd(char **command)
{
	chdir(command[1]);
	return (0);
}

int printenv(char **command)
{
	int i;

	if (*command)
	{
		i = 0;
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}

typedef int (*Builtins)(char **);
Builtins functions[] = {&exitme, &cd, &printenv};

int checkBuiltins(char *combine, char **command)
{
        int i;
        char *array[] = {"exit", "cd", "env", NULL};

        i = 0;
        while (array[i] != NULL)
        {
                if (_strcmp(array[i], command[0]) == 0)
			return (functions[i](command));
		i++;
        }
	return (execute(combine, command));
}

void looper(void)
{
	char *line;
	char **dir, **command;
	char *combine;

	while (1)
	{
		prompt();
		line = get_line();
		command = split_line(line);
		dir = dirTok();
		combine = checkPath(dir, command[0]);
                checkBuiltins(combine, command);
	}
	free(line);
	free(command);
	free(dir);
	free(combine);
}

int main()
{

	looper();
	return(0);
}
