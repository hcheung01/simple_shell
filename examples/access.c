#include "lists.h"

int main(int ac, char const**av, char const **ev)
{
	execve(av[0], *av, *ev);
	return (0);
}
