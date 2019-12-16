# Project2-Shell
Lauren and Angelique, Systems period 5
Our project is a program that creates its own command line and acts as a shell.
It
-implements execvp to parse and run typical command line arguments (cd and exit included)
-allows the user to sequentially execute multiple commands separated by a semicolon.

We had a lot of trouble with these two implementations and therefore were not able to reach the rest of our goals.

Function headers:

shell.c:
char * getInput(char s[100]);
void printArray(char ** array);
void printArray2(char *** array );
char ** parseBySpace(char input[100]);
char *** getArgsSemicolon(char * line);

main.c
int main();
