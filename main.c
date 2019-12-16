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
int main(){
  int status,f,errors;
  char *** args;
  char input[100];
  int i,semi;
  printf("$");
  getInput(input);
  args = getArgsSemicolon(input);
  i=0;
  //if there is only one command to be interpreted:
  while ((strcmp(args[i][0],"exit")!=0)){
    printArray2(args);
    i=0;
    while (args[i]) {
      printf("loop has begun\n");
    f = fork();
    if (f){
      wait(&status);
      i++;
        printf("status: %d\n",status);
      if (status==512){
        chdir(args[i][1]);
        i++;
        while(args[i]) {
          f=fork();
          i++;
          if (f) {
            wait(&status);//child process waits
          }
          else execvp(args[i-1][0], args[i]);//each command is executed
        }
      }
      //printArray(args[i]);
      printf("$");
      //getInput(input);
    }
  else{
    if (strcmp(args[i][0],"cd")==0){
      return 2;
    }
    execvp(args[i][0], args[i]);
  }
}
getInput(input);
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
