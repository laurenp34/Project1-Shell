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
<<<<<<< HEAD
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
=======
#include "shell.h"
#include "shell.c"
int main(){
  int status,f,errors;
  char *args[20];
  printf("$");
  getInput(args);
  //    printArray(args);
while (strcmp(args[0],"exit")!=0){
  f = fork();
  if (f){
    wait(&status);
  //  printf("%d",status);
    if (status==512){
        chdir(args[1]);
      }
      printArray(args);
      printf("$");
      getInput(args);
  }
  else{
    if (strcmp(args[0],"cd")==0){
      return 2;
    }
    errors=execvp(args[0], args);
  }
}
printf("errors are: %d",errors);
>>>>>>> 56fdd1898cd59b385aae1a053d4323161fd69af5
  return 0;
}
