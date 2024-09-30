/*
    Labsheet 3, Task 3
    Name: lab3-findMax.c
    Author: Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>


int findMax(int numbers[], int length){
    int max = numbers[0];
    // finding the biggest number in the array by checking it against the number folowing the current number
    for (int i = 1; i <= length; i ++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

int main(int argc, char*argv[])
{
    /* finding the amount of numbes i the command line and setting that to be the max lenght of the numbers array*/
    int lenght = argc - 1;
    int numbers[lenght];

    /*adding all the numbers in the commant line to an array*/
    for (int i = 0; i < argc; i++){
        numbers[i] = atoi(argv[i]);
    }
    /* prints the max number by passing the information into the finMax function */
    printf("%d\n", findMax(numbers, lenght));
    return 0;
}