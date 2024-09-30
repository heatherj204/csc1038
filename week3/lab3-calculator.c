/*
    Labsheet 3, Task 1
    Name: lab3-calculator.c
    Author: Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* if the user had inputted divide then this funcation is called*/

float divide(float num1, float num2){
    float total;
    total = num1 / num2;
    return total;
}

/* if the user had inputted multuply then this funcation is called*/
float multiply(float num1, float num2){
    float total;
    total = num1 * num2;
    return total;
}

int main(int argc, char*argv[])
{
    float total;

    /* defining the vars */
    float num1 = atof(argv[2]);
    float num2 = atof(argv[3]);
    /* this if statment cheack to see what the operation is pringing invalid if needed*/
    if (strcmp("divide", argv[1]) == 0){
        if (num2 == 0){
            printf("invalid\n");
            return 0;
        }
        total = divide(num1, num2);
    }
    else if (strcmp("multiply", argv[1]) == 0){
        total = multiply(num1, num2);
    }
    else{
        printf("invalid\n");
        return 0;
    }
    printf("%f\n", total);
    return 0;
}