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

void getInput(char * args[50]) {
  char s[100];
  fgets(s, 100, stdin);

  char * token; //will store start of token
  char * line = s; //the complete line stored as a pointer
  int i=0;//index of args we are up to

  while (line != NULL) {
    token = strsep(&line, " ");
    args[i] = token;
    //printf("%d: [%s]\n",i,token);
    i++;
  }
  //remove escape key from last index
  args[i-1] = strsep(&(args[i-1]), "\n");
  args[i] = NULL;

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

void runCommands(char ** args) {
  char ** temp;
  int i=0; //index of args
  int t=0; //index of temp
  while (args[i] != NULL) {
    temp[t] = args[i];
    t++;
    //if current index has a semicolon:
    if (strstr(args[i], ";") != NULL) {
      printArray(temp);
      execvp(temp[0],temp);
      temp = NULL; ///reset temp
      t=0;
    }
    i++;
  }
  print("hi\n");
  printArray(temp);
  execvp(temp[0],temp);
}

// int main() {
//   char * args[50];
//   getInput(args);
//   printArray(args);
//   return 0;
// }
