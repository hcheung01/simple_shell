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

<<<<<<< HEAD
	i = 0;
=======
>>>>>>> a28552acb775acbb0d0ce0d7510e7de30d4f0c0e
	while (*dir)
	{
		fullPath = pathCat(*dir, command);
		if (stat(fullPath, &st) == 0)
<<<<<<< HEAD
<<<<<<< HEAD
	        	return (fullPath);
		else
			return (NULL);
//		}
		//free(fullPath);
	        dir++;
=======
			return (fullPath);
		*dir++;
>>>>>>> 6935ec18987a22d73299b9b91a6417e4578b3eb9
=======
			return (fullPath);
		dir++;
>>>>>>> a28552acb775acbb0d0ce0d7510e7de30d4f0c0e
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
<<<<<<< HEAD
}

void exitme(char **command)
{
	exit(1);
}

void cd(char **command)
{
	chdir(command[1]);
}

void printenv(char **command)
{
	while (*environ)
	{
		write(1, *environ, _strlen(*environ));
		write(1, "\n", 1);
		*environ++;
	}
}

typedef void (*Builtins)(char **);
Builtins functions[] = {&exitme, &cd, &printenv};

int checkBuiltins(char **command)
=======
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
>>>>>>> a28552acb775acbb0d0ce0d7510e7de30d4f0c0e
{
        int i;
        char *array[] = {"exit", "cd", "env", NULL};

        i = 0;
        while (array[i] != NULL)
        {
                if (_strcmp(array[i], command[0]) == 0)
<<<<<<< HEAD
		{
			functions[i](command);
			return (1);
		}
                i++;
        }
	return (0);
=======
			return (functions[i](command));
		i++;
        }
	return (execute(combine, command));
>>>>>>> a28552acb775acbb0d0ce0d7510e7de30d4f0c0e
}

void looper(void)
{
	char *line;
	char **dir, **command;
<<<<<<< HEAD
	int status = 1;
	char *combine;
	int exec;
	int checker = 0;

	while (1)
	{
		prompt();/*simple prompt*/
		line = get_line();/*input from stdin as string*/
		if (line[0] == '\n')/*if input is newline continue*/
		{
			free(line);
			continue;
		}
<<<<<<< HEAD
		command = split_line(line);/*returns list of paths*/
		dir = dirTok();
		combine = checkPath(*dir, command[0]);
		execute(combine, command);
=======
		command = split_line(line);
		checker = checkBuiltins(command);
		if (checker == 0)
		{
			dir = dirTok();
			combine = checkPath(dir, command[0]);
			execute(combine, command);
		}
>>>>>>> 6935ec18987a22d73299b9b91a6417e4578b3eb9
	}
=======
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
>>>>>>> a28552acb775acbb0d0ce0d7510e7de30d4f0c0e
}

int main()
{

	looper();
	return(0);
}
