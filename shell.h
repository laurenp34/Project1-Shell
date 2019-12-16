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

char * getInput(char s[100]);
void printArray(char ** array);
void printArray2(char *** array );
char ** parseBySpace(char input[100]);
char *** getArgsSemicolon(char * line);
