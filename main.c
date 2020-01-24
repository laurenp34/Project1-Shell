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
#define STDIN 0
#define STDOUT 1
int main(){
  int status,f,errors,g,h;
  char *** args;
  char * in [10];
  char * out[10];
  char  rin[100];
  char   rout[100];
  char input[100], cwd[500];
  char * filename;
  getcwd(cwd, sizeof(cwd));
  int i,semi, fd, backup, idx, temp;
  printf("%s$", cwd);
  getInput(input);
  args = getArgsSemicolon(input);
  i=0;
  //if there is only one command to be interpreted:
  while ((strcmp(args[i][0],"exit")!=0)){
  //  printArray2(args);
    i=0;
    f=fork();
    if (f){
      wait(&status);
      if (status==512){
        if (chdir(args[i][1]) == -1) printf("Errno %d: %s\n", errno, strerror(errno));
      } else if (status != 0) {
        printf("Errno %d: %s\n", errno, strerror(errno));
      }
      //  printf("status: %d\n",status);
      //printArray(args[i]);
      getcwd(cwd, sizeof(cwd));
      printf("%s$", cwd);
      //getInput(input);
    }
    else{
    while (args[i]){
    g=fork();
    if (g){
      wait(&status);
    }
    else{
    //  printf("In second g\n");
      if (strcmp(args[i][0],"cd")==0){
        return 2;
      }
      //does args sub-array contain "|" (pipe)?
      idx=0;
      while(args[i][idx]) {
        if (strcmp(args[i][idx], "|")==0) {
          //create 2 char * arrays to pass into pipe as in and out
          int i2=0;
          printf("IN\n");
          for(i2=0;i2<idx;i2++) {
            in[i2] = args[i][i2];
            printf("\t%s\n",in[i2]);
          }
          printf("OUT\n");
          for(i2=idx+1;args[i][i2];i2++) {
            out[i2-(idx+1)] = args[i][i2];
            printf("\t%s\n",out[i2-(idx+1)]);
          }
          // exec_pipe(in, out);
          exec_pipe(args[i][0], args[i][2]);
          return 0;
        }
        if (strcmp(args[i][idx],">")==0 || strcmp(args[i][idx],"<")==0 || strcmp(args[i][idx],">>")==0){
          char * temp1= args[i][idx];
          args[i][idx]=NULL;

        //  printf("found one");
        //  printArray2(args);
            if (strcmp(temp1,">")==0){//putting stuff in a file
            //  printf("In second one: %s\n",args[i][idx+1]);
              strcpy(rout,args[i][idx+1]);
          //    printf("[%s] is the name of the file (>)\n",rout);
              fd=open(rout, O_CREAT | O_WRONLY, 0744);
              if (fd<0) printf ("Error opening file");
             temp =dup(STDOUT);
              dup2(fd, STDOUT);
              close(fd);
            }
            else if (strcmp(temp1,">>")==0){
              strcpy(rout,args[i][idx+1]);
        //      printf("[%s] is the name of the file\n",rout);
              fd=open(rout, O_WRONLY | O_APPEND, 0744);
              if (fd<0) printf ("Error opening file");
             temp =dup(STDOUT);
              dup2(fd, STDOUT);
              close(fd);
            }
            else if (strcmp(temp1,"<")==0){//getting stuff from a file
              strcpy(rout,args[i][idx+1]);
          //     printf("[%s] is that ",rout);
              fd=open(rin, O_RDONLY , 0744);
              temp =dup(STDIN);
              dup2(fd, STDIN);
              close(fd);
            }

  }
      idx++;
      }
    //  printArray2(args);
    //  printf("Printing array. Here it is. \n");

        if (execvp(args[i][0], args[i]) == -1) {
          // printf("Errno %d: %s\n", errno, strerror(errno));
          exit(errno);
        }

    }
    i++;
  }
return WEXITSTATUS(status);
}
getInput(input);
//free(args);
args = getArgsSemicolon(input);
}
return 0;
}
