#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/wait.h>
#include "shell.c"
int main(){
  int status;
  int f;
  int f2;
  int i;
  char * args[50][50];
  printf("$");
  getInput(args);
  while (strcmp(args[0][0],"exit")!=0){
    f = fork();
    if (f){
      wait(&status);
        printf("$");
          getInput(args);
    }
    else{
    //  if (strcmp(r,"exit")==0) exit();
      //runCommands(args);
      i=0;
      while(args[i][0] != NULL) {
        f2 = fork();
        if (f2) {
          wait(&status);
        }
        else {
          execvp(args[i][0], args[i]);
        }
      }
    }
  }
  return 0;
}
