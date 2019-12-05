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
#include "shell.h"
#include "shell.c"
int main(){
  int status,f;
  char **args;
        printf("$");
  getInput(args);
while (strcmp(args[0],"exit")!=0){
  f = fork();
  if (f){
    wait(&status);
  //  printf("%d",status);
    if (status==512){
        chdir(args[1]);
      }
      printf("$");
      getInput(args);
  }
  else{
    if (strcmp(args[0],"cd")==0){
      return 2;
    }
    execvp(args[0], args);
  }
}
  return 0;
}
