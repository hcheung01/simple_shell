#include "lists.h"

int exitme(char **command)
{
	if (_strcmp(command[0], "exit"))
		exit(1);
	return (0);
}

int cd(char **command)
{
	chdir(command[1]);
	return (1);
}

int printenv(char **command)
{
	if (command[0] != NULL)
		while (*environ)
		{
			write(1, *environ, _strlen(*environ));
			write(1, "\n", 1);
			environ++;
		}
	return (0);
}

typedef int (*Builtins)(char **);
Builtins functions[] = {&exitme, &cd, &printenv};

int checkBuiltins(char **command)
{
        int i;
        char *array[] = {"exit", "cd", "env", NULL};

        i = 0;
        while (array[i] != NULL)
        {
                if (_strcmp(array[i], command[0]) == 0)
		{
			functions[i](command);
			return (1);
		}
                i++;
        }
	return (0);
}

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

void looper(void)
{
	char *line;
	char **dir, **command;
	char *combine;
	int checker;

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
		checker = checkBuiltins(command);
		if (checker == 0)
		{
			dir = dirTok();
			combine = checkPath(dir, command[0]);
			execute(combine, command);
		}
	}
}

int main(void)
{

	looper();
	return(0);
}
