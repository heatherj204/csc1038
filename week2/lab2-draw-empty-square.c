/*
    Labsheet 2, Task 2
    Name: lab2-draw-empty-square.c
    Author: Heather Johnston
 */

//includes
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    int value = atoi(argv[1]);

    // top line
    for (int i = 0; i < value; i++)
    {
        /* code */
        printf("*");
    }
    printf("\n");

    for (int i = 0; i < (value - 2); i++)
    {
        /* code */
        printf("*");
        // printing the spaces in each line
        for (int j = 0; j < (value - 2); j++)
        {
            printf(" ");
        }
        printf("*\n");
    }

    // bottom line
    for (int i = 0; i < value; i++)
    {
        /* code */
        printf("*");
    }
    printf("\n");

    return 0;
}