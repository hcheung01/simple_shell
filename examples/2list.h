#ifndef _LISTS_H_
#define _LISTS_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;
char *getPath(void);
char *getDir(char *args);
char *dirTok(char *args);
char *pathCat(char *dir, char *av);

#endif
