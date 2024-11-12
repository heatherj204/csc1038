/*
    Labsheet 9, Task 3
    Name: lab9-largest-twice.c
    Author: Heather Johnston
*/

#include <stdio.h>
#include <stdlib.h>

// function prototypes
void parseInput(char *argv[], int argc, int *pNumbers);
int findNumber(int *pNumbers, int argc);

// main function
int main(int argc, char *argv[]){

    //dynamically allocating memory for the array of numbers
    int *pNumbers = (int*)calloc(argc - 1, sizeof(int));

    //parsing the input to create the array of numbers
    parseInput(argv, argc, pNumbers);

    int result = findNumber(pNumbers, argc);

    printf("%d\n", result);

    //freeing memory
    free(pNumbers);
    return 0;
}

void parseInput(char *argv[], int argc, int *pNumbers){
    /* going over the command line arguments to add each of them to the array */
    for (int i = 1; i < argc; i++){
        pNumbers[i - 1] = atoi(argv[i]);
    }
}

int findNumber(int *pNumbers, int argc){
    int n = argc - 1;
    int largestTwice = 0;   //setting the number to 0 initially in the case that there will be no biggest number
    /* iterates over all elements in the array to try and find number that is at least twice as big as another*/
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (pNumbers[j] * 2 < pNumbers[i]){ // if the number at i is at least twice as big number at j the number at i is set to the largest
                largestTwice = pNumbers[i];
            }
        }
    }
    return largestTwice;
}