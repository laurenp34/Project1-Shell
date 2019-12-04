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

#include "shell.h"

int main(){
  printf("$");
  int status;
  char **args =getInput();
  f = fork();
  if (f){
    wait(status);
  }
  else{
    if (strcmp(r,"exit")==0) exit();
    execvp(args);
  }
  return 0;
}
