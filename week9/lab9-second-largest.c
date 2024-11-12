/*
    Labsheet 9, Task 2
    Name: lab9-second-largest.c
    Author: Heather Johnston
*/

#include <stdio.h>
#include <stdlib.h>

void parseInput(char *argv[], float *pNumbers, int argc);
float getSecond(float *pNumbers, int argc);

int main(int argc, char *argv[]){

    /* dynamically allocating memory for the array of numbers */
    float *pNumbers = (float*)calloc(argc - 1, sizeof(float));

    parseInput(argv, pNumbers, argc);   //parsing the input to create the array of numbers

    float result = getSecond(pNumbers, argc); //calling the function to find the second largest number
    printf("%.1f\n", result);
    free(pNumbers);
    return 0;
}

void parseInput(char *argv[], float *pNumbers, int argc){
    /* going over the command line arguments to add each of them to the array */
    for (int i = 1; i < argc; i++){
        pNumbers[i - 1] = atof(argv[i]);
    }
}

float getSecond(float *pNumbers, int argc){
    int n = argc - 1;

    /* initialising the max and second largest */
    float max = pNumbers[0];
    float secondMax = pNumbers[0];

    /* iterating over the array to fid the largest number */
    for (int i = 1; i < n; i++){
        if (pNumbers[i] > max){
            max = pNumbers[i];
        }
    }
    /* iterating over the array to check for the second largest number */
    for (int i = 1; i < n; i++){
        if (pNumbers[i] != max && pNumbers[i] > secondMax){
            secondMax = pNumbers[i];
        }
    }
    return secondMax;
}
