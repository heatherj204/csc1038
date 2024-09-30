/*
    Labsheet 3, Task 4
    Name: lab3-search-number.c
    Author: Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>

int searchNum(int numbers[], int length, int target){
    int position = -1; // setting the position to a number that cannot be found in the array
    /* find the position of the target number by comparing aech item in the array to the target number*/
    for (int i = 0; i < length; i ++) {
        if (numbers[i] == target) {
            position = i;
        }
    }
    return position;
}

int main(int argc, char*argv[]){
    int target = atoi(argv[1]);
    int length = argc - 2; // Adjust the length to account for the target number
    int numbers[length];

    /* loop through the arguments to add them to the number array */
    for (int i = 2; i < argc; i++){
        numbers[i - 2] = atoi(argv[i]);
    }
    int position = searchNum(numbers, length, target);
    if (position < 0){
        printf("%d not found\n", target);
    }
    else{
        printf("Found %d at %d\n", target, position);
    }
    return 0;
}
