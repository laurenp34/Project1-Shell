#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

#include "shell.c"

<<<<<<< HEAD
int getInput(char * args1[50], char * args[20][50]);
void printArray(char ** args);
=======

char * getInput(char s[100]);
void printArray(char ** array);
>>>>>>> f9b83a836ae4914ea36ca6acfc920607a50730fe
void printArray2(char *** array );
char ** parseBySpace(char input[100]);
char *** getArgsSemicolon(char * line);
