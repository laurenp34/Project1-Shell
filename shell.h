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


void getInput(char * args[20][50]);
void printArray(char ** args);
void printArray2(char *** array );
void runCommands(char ** args);
