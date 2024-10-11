/*
    Labsheet 5, Task 2
    Name: lab5-sort-numbers.c
    Author: Heather Johnston
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* fuinction prototypes */
void asc(char*, int);
void desc(char*, int);

int main(int argc, char*argv[]){
    int length = atoi(argv[1]);
    char numbers[length];
    for (int i = 0; i < length; i++){
        numbers[i] = atoi(argv[i + 2]);
        // printf("%d\n", atoi(argv[i + 2]));
    }

    char *order = argv[length + 2];     // getting the order from the command line
    // printf("%s\n", order);

    void (*pfunction)(char*, int);// Function pointer declaration

    /* checking to see what the order is*/
    if (strcmp(order, "asc") == 0){
        /* calling the asc function if the order is meant to be asc*/
        pfunction = asc;
        pfunction(numbers, length);
    }
    else if (strcmp(order, "desc") == 0){
        /* calling the desc function if the order is meant to be desc*/
        pfunction = desc;
        pfunction(numbers, length);
    }
    
    /* printing out each element in the function */
    printf("Sorted numbers: ");
    for(int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", numbers[i]);  // Print the last element without a trailing space
        } else {
            printf("%d ", numbers[i]);  // Print the element followed by a space
        }
    }
    printf("\n");

    return 0;
}

/* using void functions to change the array itself without needing to return anything*/
void asc(char *numbers, int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (numbers[i] > numbers[j]){
                    int temp;
                    temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
            }
        }
    }
}

void desc(char *numbers, int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (numbers[i] < numbers[j]){
                    int temp;
                    temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
            }
        }
    }
}
