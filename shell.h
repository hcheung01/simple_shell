#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
extern char **environ;
extern int dircount;
#define DELIM " \n\a\t"

void env(char **env);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void prompt(void);
char *get_line(void);
char **split_line(char *line);
char *get_env(char **env);
char *pathCat(char *dir, char *av);
char **dirTok(char **env);

void looper(char **env);
char *checkPath(char **dir, char *command);
int execute(char *fullPath, char **command);
int exitme(char **command);
int cd(char **command);
int printenv(char **command);
int checkBuiltins(char *combine, char **command);
#endif
