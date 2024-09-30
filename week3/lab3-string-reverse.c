/*
    Labsheet 3, Task 2
    Name: lab3-string-reverse.c
    Author: Heather Johnston
 */

// includes
#include <stdio.h>
#include <string.h>

void reverseStr(char line[]){
    int length = strlen(line); // getting the lengh of the line
    int j;

    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = line[i]; // holds the value of line[i] so that line[i] can get changed
        line[i] = line[j]; // changes the valur of line[i] to line[j]
        line[j] = temp; // Move the value of temp (original line[i]) into line[j])
    }

}

int main(int argc, char*argv[]){
    char line[50];
    // copy argv[1] to the var lie
    strcpy(line, argv[1]);
    // call the revese string function
    reverseStr(line);
    printf("%s\n", line);
    return 0;
}