/*
    Labsheet 4, Task 2
    Name: lab4-find-most-character.c
    Author: Heather Johnston
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findMost(char *string){
    /* finds the most common char by comapring one char agains every char in the string, then moving on to the next char*/
    char c;
    int max = 0;
    int count;

    for (int i = 0; i < strlen(string); i++){
        count = 0;
        for (int j = 0; j < strlen(string); j++){
            if (string[i] == ' '){
                break;
            }
            /* cheching to see if the charachters match */
            else if (string[j] == string[i]){
                count++;
            }
        }
        /* setting the most common char after each pass*/
        if (max < count){
            max = count;
            c = string[i];
        }
    }
    return c;
}

int main(int argc, char*argv[]){
    /* getting the string from the command line */
    char *pString = argv[1];
    /* call the function to find the most common char */
    char mostFreq = findMost(pString);

    printf("%c\n", mostFreq);
    return 0;
}