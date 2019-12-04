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
  printf("$");
  int status,f;
  char **args;
  getInput(args);
  fork();
  if (f){
    wait(status);
  }
  else{
  //  if (strcmp(r,"exit")==0) exit();
    execvp(args[0],args);
  }
  return 0;
}
