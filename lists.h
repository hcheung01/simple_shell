#ifndef _LISTS_H_
#define _LISTS_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
extern int dircount;
extern char **environ;
#define DELIM " \n\a\t"

void env(void);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void prompt(void);
char *get_line(void);
char **split_line(char *line);
char *get_env(void);
char *pathCat(char *dir, char *av);
char **dirTok(void);

void looper(void);
char *checkPath(char **dir, char *command);
int execute(char *fullPath, char **command);
int exitme(char **command);
int cd(char **command);
int printenv(char **command);
int checkBuiltins(char *combine, char **command);
#endif
