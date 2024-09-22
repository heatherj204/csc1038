/*
    Labsheet 2, Task 1
    Name: lab2-cylinder-area.c
    Author: Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

int main(int argc, char*argv[]){
    // checking to see if the correct amount of inputs were entered
    if (argc == 1){
        printf("No input given!\n");
        return 1;
    }
    else if (argc == 2){
        printf("Two arguments needed!\n");
        return 1;
    }

    int rad = atoi(argv[1]);
    int height = atoi(argv[2]);

    // checking to see if the value inputed are positive
    if (rad < 0 || height < 0){
        printf("The radius or height cannot be negitive\n");
        return 1;
    }

    // calculating the area
    float area = (2 * PI *rad * height) + (2 * PI * (rad * rad));
    // printing the area to two decimal places if needed
    printf("%.2f\n", area);

    return 0;
}