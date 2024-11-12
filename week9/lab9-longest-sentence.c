/*
    Labsheet 9, Task 4
    Name: lab9-longest-sentence.c
    Author: Heather Johnston
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes
void parseInput(char *argv[], int argc, char **pAllStrings);
int getLength(int argc, char **pAllStrings, int *pStringLength);
void getLongestString(int argc, char **pAllStrings, int *pStringLength);

//main function
int main(int argc, char *argv[]){

    //dynamically allocating memory for the array of all the strings
    char **pAllStrings = (char**)malloc((argc - 1) * sizeof(char*));

    //calling function to parse inputs
    parseInput(argv, argc, pAllStrings);

    //dynamically allocating memory for the array that holds the length of each string
    int *pStringLength = (int*)calloc(argc - 1, sizeof(int));

    //calling function that will get the length of each string and add it to the array defined earlier
    getLength(argc, pAllStrings, pStringLength);

    //calling function that will find the length of longest string(s) and print that string(s)
    getLongestString(argc, pAllStrings, pStringLength);

    free(pAllStrings);
    free(pStringLength);

    return 0;
}

void parseInput(char *argv[], int argc, char **pAllStrings){
    //going over the command line and adding each string to the array
    for (int i = 1; i < argc; i++){
        pAllStrings[i - 1] = argv[i]; // -1 accounts for the file name
        //printf("%s\n",pAllStrings[i - 1]);
    }
}

int getLength(int argc, char **pAllStrings, int *pStringLength){
    //going over the strings array to add the length of each string to the array
    for (int i = 0; i < argc - 1; i++){ // -1 account for the file name
        pStringLength[i] = strlen(pAllStrings[i]);
        //printf("%d\n", pStringLength[i]);
    }
}

void getLongestString(int argc, char **pAllStrings, int *pStringLength){
    int longestString = pStringLength[0];
    //finding the length of the longest string(s)
    for (int i = 0; i < argc - 1; i++){
        if (pStringLength[i] > longestString){
            longestString = pStringLength[i];
        }
    }
    //finding string(s) that have the same length as the longest and printing them
    for (int i = 0; i < argc - 1; i++){
        if (pStringLength[i] == longestString){
            printf("%s\n", pAllStrings[i]);
        }
    }
}