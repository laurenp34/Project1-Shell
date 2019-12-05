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

void getInput(char * args[50][50]) {
  char s[100];
  fgets(s, 100, stdin);

  int status;

  char * token; //will store start of token
  char * line = s; //the complete line stored as a pointer
  int i=0;//index of args we are up to

  char * temp[50]; //stores different commands

  //separate the diff commands by semicolon:
  while (line != NULL) {
    token = strsep(&line, ";");
    temp[i] = token;
    i++;
  }
  temp[i] = NULL;

  //loop through commands in temp and separate by space in each
  int i2=0;
  while (temp[i2] != NULL) {
    line = temp[i2];
    i=0;
    while (line != NULL) {
      token = strsep(&line, " ");
      args[i2][i] = token;
      //printf("%d: [%s]\n",i,token);
      i++;
    }
    //remove escape key from last index
    args[i2][i-1] = strsep(&(args[i-1]), "\n");
    args[i2][i] = NULL;
    i2++;
  }
  args[i2][0] = NULL;

}

void printArray(char ** array) {
  printf("[");
  int c = 0;

  while (array[c] != NULL) {
    printf("'%s', ", array[c]);
    c ++;
  }
  printf("]\n");
}

void printArray2(char *** array ){
  printf("[");
  int c = 0;
  while (array[c] != NULL) {
    printArray(array[c]);
    c++;
  }
  printf("]\n");
}

void runCommands(char ** args) {
  printf("hi\n");
  char ** temp;
  int i=0; //index of args
  int t=0; //index of temp
  int f, status;
  while (args[i] != NULL) {
    temp[t] = args[i];
    printf("%s.\n", temp[t]);
    t++;
    //if current index has a semicolon:
    if (strstr(args[i], ";") != NULL) {
      f = fork();
      if (f) {
        wait(&status);
        printf("cmd\n");
      } else {
        printArray(temp);
        execvp(temp[0],temp);
        temp = NULL; ///reset temp
        t=0;
      }
    }
    i++;
  }
  printf("hi\n");
  printArray(temp);
  execvp(temp[0],temp);
}

// int main() {
//   char * args[50];
//   getInput(args);
//   printArray(args);
//   return 0;
// }
