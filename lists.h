#ifndef _LISTS_H_
#define _LISTS_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

pid_t getpid(void);
pid_t getppid(void);
pid_t getpidmax(void);
char *read_line_buff(void);
<<<<<<< HEAD
void shl_loop(void);
char *shl_get_ln(void);
char *_strdup(char *str);
char **shl_parse_ln(char *ln);
int shl_start(char *args[]);
=======

/* parse functions */
char *_strdup(char *str);
char **shl_parse_ln(char *ln);

>>>>>>> 7666add1a60d0dd011c48796e40c222f1f4999e1
#endif
