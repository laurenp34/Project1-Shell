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

void printArray(char **) {
  printf("[");
  int c = 0;
  for (c=0;c<i;c++) {
    printf("'%s', ", args[c]);
  }
  printf("]\n");
}

int main() {
  char * args[50] = getInput();
  printArray(args);
  return 0;
}
