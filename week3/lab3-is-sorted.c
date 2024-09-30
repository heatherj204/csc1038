/*
    Labsheet 3, Task 6
    Name: lab3-is-sorted.c
    Author: Heather Johnston
 */

//  includes
#include <stdio.h>
#include <stdlib.h>

/* Using a void function to eddit the array in place*/
void sortArray(int numbers[], int length){
    int i, j, temp;
    for (i = 0; i < length - 1; i++) {
        // Last i elements are already in place
        for (j = 0; j < length - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

}

int main(int argc, char *argv[]){
    int length = argc - 1;
    int numbers[length];
/* Convert the integers in the command line to the numbers array */
    for (int i = 0; i < length; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }
    /* call the sort functions */
    sortArray(numbers, length);

    /* Print out each integer in the array line by line*/
    for (int i = 0; i < length; i++) {
        printf("%d\n", numbers[i]);
    }
    return 0;
}