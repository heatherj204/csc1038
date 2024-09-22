/*
    Labsheet 2, Task 3
    Name: lab2-count-odd-number.c
    Author: Heather Johnston
 */

// inlcudes
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    // creating the array and giving it a max amount of vales
    int amount = 10;
    int numbers[amount];

    for (int i = 0; i < argc; i++){
        numbers[i] = atoi(argv[i]);
    }

    int countOdd = 0;

    for (int i = 0; i < argc; i++){
        if (numbers[i] % 2 == 1){
            countOdd++;
        }
    }

    printf("%d\n", countOdd);
    return 0;
}