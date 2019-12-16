# Project2-Shell
Lauren and Angelique, Systems period 5
Our project is a program that creates its own command line and acts as a shell.
It
a) implements execvp to parse and run typical command line arguments (cd and exit included)
b) allows the user to sequentially execute multiple commands separated by a semicolon.

We had a lot of trouble with these two implementations and therefore were not able to reach the rest of our goals. We were able to quickly get a simple shell working with exit and cd, but once we added semicolons and started to work with multiple commands we struggled. We did not attempt the other implementations.

The bugs we have found in our program include:
a)cd only works in isolation. When coupled with other functions through semicolon, it stops working
b)Pressing enter without any command input returns a makefile error.

Function headers:

shell.c:
char * getInput(char s[100]);
This function receives input and removes the final line break.

void printArray(char ** array);
void printArray2(char *** array );
These two are for testing purposes and print out the arrays.

char ** parseBySpace(char input[100]);
This breaks up the line into groups of words, separating by spaces.

char *** getArgsSemicolon(char * line);
This parses through these by semicolon, forming a two-dimensional array of strings.

main.c
int main();
