#ifndef _LISTS_H_
#define _LISTS_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>

#define DELIM " /n/a/t"
extern char **environ;
/*static char **environ;*/

void prompt(void);
char *get_line(void);
char **split_line(char *line);
void shl_loop(void);
char *shl_get_ln(void);
char *_strdup(char *str);
char **shl_parse_ln(char *ln);
int shl_start(char *args[]);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *string_nconcat(char *s1, char *s2, unsigned int n);
int _strlen(char *s);
char *shl_path(void);
char **shl_path_buf(char *start);
char *shl_stat(char **av, char *getln);
#endif
