#include "lists.h"

/*int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1] != 0))
		{
			perror("lsh");
		}
	}
	return (1);
}


int lsh_exit(char **args)
{
	return 0;
}

char *builtin[] = {
	"cd",
	"exit"
};



int execArg(char **args)
{
	pid_t child_pid;
	int result = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		result = execve(args[0], args, NULL);
		if (execve(args[0], args, NULL) == -1)
		{
			perror("error return from exec");
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("error pid is less than 0");
	}
	else
	{
		wait(NULL);
		printf("THIS PID IS WORKING\n");
	}
	return (1);
} */

int main(void)
{
	char *line;
	char **args;
	int i = 0, k = 0;
	int exec;
	int compare;

	while (i < 1)
	{
		prompt();
		line = get_line();
		args = split_line(line);

	}
	return (0);
}
