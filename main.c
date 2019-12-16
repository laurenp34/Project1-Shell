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
void cdfunc(int i, char *** args){
  int h,status;
  chdir(args[i][1]);
      printf("made it here! %d",i);
      i+=2;
  while(args[i]) {
    printf("made it in!");
    h=fork();
    i++;
    if (h) {
      wait(&status);//child process waits
    }
    else execvp(args[i-1][0], args[i-1]);//each command is executed
  }
}

int main(){
  int status,f,errors,g,h;
  char *** args;
  char input[100], cwd[500];
  char * filename;
  getcwd(cwd, sizeof(cwd));
  int i,semi, fd, backup;
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
      // if (strcmp(args[i][1], ">") == 0) {
      //   backup = dup(1); //backup of stdout
      //   filename = args[i][2];
      //   fd = open(filename, 0644);
      //   dup2(fd, 1);
      //   return 3;
      // }
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
// while (strcmp(args[i][0],"exit")!=0 && semi==2){
//   f = fork();
// //Parent runs after ALL children are done
//   if (f){
//     wait(&status);
//   //  printf("%d",status);
//     if (status==512){//handles a cd internally
//         chdir(args[i][1]);//executes the cd
//           while(args[i][0]){//while there are commands to look at
//             f=fork();
//             i++;
//             if (f) {
//               wait(&status);//child process waits
//             }
//             else execvp(args[i-1][0], args[i]);//each command is executed
//           }
//         }
//       printArray(args);//once children have run
//       printf("$");
//       semi=getInput(args); //takes in new input
//   }
//   //Children run repeatedly
//   else{
//     while(args[i][0]){
//       i++;
//       if (strcmp(args[i-1][0],"cd")==0){
//         return 2;//delegates back to parent class
//       }
//       f = fork();
//       if (f) {
//         wait(&status);//executes children one by one
//       }
//       else execvp(args[i-1][0], args[i]);
// }
// }
// }
return 0;
}
