/*
    Labsheet 2, Task 4
    Name: lab2-find-even-number.c
    Author: Heather Johnston
 */

// inlcudes
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    // creating the array and giving it a max amount of vales
    int amount = 10;
    int numbers[amount];

    // looping over all args to add them to array
    for (int i = 0; i < argc; i++){
        numbers[i] = atoi(argv[i]);
    }

    int allEven = 0;
    // looping over all of the neber to find even nubers
    for (int i = 1; i < argc; i++){
        if (numbers[i] % 2 == 0){
            printf("%d - %d\n", i - 1, numbers[i]);
            allEven++;
        }
    }

    // in case that there are no even numbers
    if (allEven == 0){
        printf("Not found!\n");
    }
    return 0;
}