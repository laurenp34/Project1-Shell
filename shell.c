#include <stdio.h>
#include <ctype.h>
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


void printArray(char ** array) {
  printf("[");
  int c = 0;

  while (array[c]) {
    printf("'%s',", array[c]);
    c ++;
  }
  printf("]\n");
}

void printArray2(char *** array ){
  printf("{");
  int c = 0;
  while (array[c] != NULL) {
    printArray(array[c]);
    c++;
  }
  printf("}\n");
}


char * getInput(char s[100]) {
  fgets(s, 100, stdin);
  //printf("input: %s\n", s);
  char * temp = s;
  s = strsep(&temp, "\n");
  return s;
}

char ** parseBySpace(char input[100]) {
  //printf("hi\n");
  char ** out = malloc(20 * sizeof (char*));
  int i = 0;
  char * line = input;
  char * token;
  while (line){
    token = strsep(&line, " ");
    //printf("token: %s\n", token);
    // printf("out[i]:%s\n", out[i]);
    out[i] = token;
    //printf("out[i]:%s\n", out[i]);
    //printf("what\n");
    i++;
  }
  //printf("done\n");
  //char * last = out[i-1];
  // printf("last: %s", last);
  //out[i-1] = strsep(&last, "\n");
  out[i] = NULL;
  //printf("finished parsing line. \n");
  //printArray(out);
  //printf("\n");
  return out;

  // // char *s1 = line;
  // char * out[100];
  // int i=0;
  // while (s1){
  //   out[i] = strsep(&s1, "-");
  //   i++;
  // }
  // out[i] = NULL;
}

char *** getArgsSemicolon(char * line) {
  char *** args2 = malloc(20 * 20 * sizeof(char *));
  char * token = line;
  int i2 = 0;
  line = strsep(&token, "\n");
  //printf("INPUT: '%s'\n", line);
  while (line && strlen(line)>0) {
    //printf("line: '%s'\n", line);
    token = strsep(&line, ";");
    //printf("parsing: %s\n", token);
    args2[i2] = parseBySpace(token);
    printArray(args2[i2]);
    //printf("hi again\n");
    //printf("line after parsing:%s\n", line);
    //printf("len of line:%d\n",strlen(line));
    //printf("line null: %d\n", line);
    i2++;
  }
  args2[i2] = NULL;
  //printArray(args2[0]);
  //printArray(args2[1]);
  return args2;
}




// int main() {
//   char ** a1;
//   char *** a2;
//   char s[100];
//   getInput(s);
//   printf("input: %s\n", s);
//   if (strstr(s, ";")) {
//     printf("there is a secmicolon\n");
//     a2 = getArgsSemicolon(s);
//     printArray2(a2);
//   } else {
//     a2 = getArgsSemicolon(s);
//     printArray2(a2);
//   }
//
//   // char line[100] = "woah this-is-cool";
//   // char * out[20];
//   // parseBySpace(line, out);
//   // printArray(out);
//   // // parseBySpace(in, args);
//   // // printArray(args);
//
//   return 0;
// }
