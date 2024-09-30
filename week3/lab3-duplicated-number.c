/*
    Labsheet 3, Task 5
    Name: lab3-duplicated-number.c
    Author: Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>

// Function to find the duplicate number in the array
int find_duplicate(int numbers[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] == numbers[j]) {
                return numbers[i];  // Return the duplicated number
            }
        }
    }
    return -1;  // Return -1 if no duplicate is found
}

int main(int argc, char *argv[]) {
    int length = argc - 1;
    int numbers[length];
    /* loop through the arguments to add them to the number array */
    for (int i = 0; i < length; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }
    // Find the duplicate number
    int duplicate = find_duplicate(numbers, length);
    if (duplicate != -1) {
        printf("%d\n", duplicate);
    } else {
        printf("no duplicated number\n");
    }

    return 0;
}
