#ifndef _LISTS_H_
#define _LISTS_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <sys/stat.h>

#define DELIM " /n/a/t"
extern char **environ;
static char **environ;

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
char *shl_stat(char **tokens, char *getln);
void free_grid(int **grid, int height);
=======
extern int dircount;
extern char **environ;
#define DELIM " \n\a\t"

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void prompt(void);
char *get_line(void);
char **split_line(char *line);
char *get_env(void);
char *pathCat(char *dir, char *av);
char **dirTok(void);
>>>>>>> 579ab08cf75b54714d1730c0816341e199033e89
#endif
