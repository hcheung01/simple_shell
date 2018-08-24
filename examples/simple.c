#include "lists.h"
int main(void)
{
	int runme = 0;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	pid_t my_pid;
	pid_t pid;

	my_pid = getpid();
	printf("Before fork id is: %u\n", my_pid);

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
		runme = execve(argv[0], argv, NULL);
		if (runme == -1)
			perror("Error");
		exit(runme);
	}
	else
		wait(NULL);


	return (0);
}
