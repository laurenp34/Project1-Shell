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


int getInput(char * args1[50], char * args[20][50]);
void printArray(char ** args);
void printArray2(char *** array );
void runCommands(char ** args);
