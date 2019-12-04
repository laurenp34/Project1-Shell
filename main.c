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
#include <sys/wait.h>
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
      printf("$");
        getInput(args);
  }
  else{
  //  if (strcmp(r,"exit")==0) exit();
    execvp(args[0],args);
  }
}
  return 0;
}
