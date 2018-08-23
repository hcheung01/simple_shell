#include "lists.h"

/**
 * getpid - function with no arguments
 *
 * Description: get child process id
 * Return: process id
 */
pid_t getpid(void)
{
        pid_t my_pid;

        my_pid = getpid();
        return (my_pid);
}

/**
 * getppid - function with no arguments
 *
 * Description: get parent process id
 * Return: process id
 */
/*pid_t getppid(void)
{
        pid_t my_ppid;

        my_ppid = getppid();
        return (my_ppid);
}
*/
/**
 * getpid - function with no arguments
 *
 * Description: get maximum process id running
 * Return: process id value
 */
/*pid_t getpidmax(void)
{
        pid_t pidmax;

        pidmax = pid_max();
        return(pidmax);
}
*/
