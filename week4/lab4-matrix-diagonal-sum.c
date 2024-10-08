/*
    Labsheet 4, Task 3
    Name: lab4-matrix-diagonal-sum.c
    Author: Heather Johnston
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>
int sumDiagonals(int n, char* argv[], int argc){
    int length = argc - 2;
    int *nums[length];
    int diagonalSum = 0;

    for (int i = 0; i < n; i++){
        nums[n] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++){
            nums[i][j] = atoi(argv[2 + i * n + j]);
            /* If it's a diagonal element (i == j), add it to the diagonalSum */
            if (i == j) {
                diagonalSum += nums[i][j];
            }
        }
    }
    return diagonalSum;
}

int main(int argc, char*argv[]){
    /* getting n from the command line */
    int n = atoi(argv[1]);

    /* Call function to populate matrix and get diagonal sum */
    int diagonalSum = sumDiagonals(n, argv, argc);

    /* print the total sum of diagonals */
    printf("%d\n", diagonalSum);

    return 0;
}


