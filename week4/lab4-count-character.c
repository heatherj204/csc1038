/*
    Labsheet 4, Task 1
    Name: lab4-count-character.c
    Author: Heather Johnston
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(char *string, char target){
    /* searching for the charachter to match in the string */
    int i = 0;
        while (string = strchr(string, target)){
        i++;
        string++;
    }
    return i;
}

int main(int argc, char*argv[]){

    /* setting the target from the command line */
    char target = argv[1][0];
    /* getting the string to search from the command line */
    char* pstring = argv[2];

    int i = 0;

    printf("%d\n", count(pstring, target));
    return 0;

}