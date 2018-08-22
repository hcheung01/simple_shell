#ifndef _LISTS_H_
#define _LISTS_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


void shl_loop(void);
char *shl_get_ln(void);
char *_strdup(char *str);
char **shl_parse_ln(char *ln);
int shl_start(char *args[]);
int _strcmp(char *s1, char *s2);
#endif
