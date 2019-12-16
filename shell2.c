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

char **  parseargs(char * line){
  int i = 0;
  char * args[50];
  char * token;
  while (line){
    token = strsep(&line, " ");
    args[i] = token;
    i++;
  }
  args[i-1] = strsep(&(args[i-1]), "\n");
  args[i] = NULL;
  return args;
}

int getInput(char** args2[50]) {
  char s[100];
  int i, i2;

  int status;

  char * token; //will store start of token
  char * line = s; //the complete line stored as a pointer
   i=0;//index of args we are up to

  char * temp[50]; //stores different commands
  fgets(s, 100, stdin);
  if (strchr(s, ';') > 0) {
    printf("There is a semicolon\n");
    //separate the diff commands by semicolon:
    while (line) {
      token = strsep(&line, ";");
      temp[i] = token;
      i++;
    //  printf("In the loop");
    }
    temp[i] = NULL;
    i=0;
    while (temp[i]){
      printf("[%s]\n",temp[i]);
      i++;
    }
    i=0;
    while (temp[i]){
      printf("In the loop");
      args2[i2]=parseargs(temp[i]);
      i++;
    }
  }
  i2=0;
  i=0;
while (args2[i2][i]){
while(args2[i2][i]){
  printf("%s",args2[i2][i]);
  i++;
}
i2++;
}
    return 1;
      /*
      //remove escape key from last index
      args2[i2][i-1] = strsep((args2[i-1]), "\n");
      args2[i2][i] = NULL;
      i2++;
    }
    args2[i2][0] = NULL;*/

  }

// void printArray(char * array[50]) {
//   printf("[");
//   int c = 0;
//
//   while (c<6) {
//     printf("'%s',", array[c]);
//     c ++;
//   }
//   printf("]\n");
// }
//
// void printArray2(char * array[20][50] ){
//   printf("[");
//   int c = 0;
//   while (array[c] != NULL) {
//     printArray(array[c]);
//     c++;
//   }
//   printf("]\n");
// }
//
// void runCommands(char ** args) {
//   printf("hi\n");
//   char ** temp;
//   int i=0; //index of args
//   int t=0; //index of temp
//   int f, status;
//   while (args[i]) {
//     temp[t] = args[i];
//     printf("%s.\n", temp[t]);
//     t++;
//     //if current index has a semicolon:
//     if (strstr(args[i], ";") != NULL) {
//       f = fork();
//       if (f) {
//         wait(&status);
//         printf("cmd\n");
//       } else {
//         printArray(temp);
//         execvp(temp[0],temp);
//         temp = NULL; ///reset temp
//         t=0;
//       }
//     }
//     i++;
//   }
//   printf("hi\n");
//   printArray(temp);
//   execvp(temp[0],temp);
// }

int main() {
  char * a1[50];
  char * a2[20][50];
int i;
  i=getInput(a1);
  return 0;
}
