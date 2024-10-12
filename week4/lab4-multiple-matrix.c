/*
    Labsheet 4, Task 5
    Name: lab4-multiple-matrix.c
    Author: Heather Johnston
 */

#include <stdio.h>
#include <stdlib.h>

// Function to multiply two matrices
void multiply_matrices(int *matrix1, int m1, int n1, int *matrix2, int m2, int n2, int *result) {
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i * n2 + j] = 0;
            for (int k = 0; k < n1; k++) {
                result[i * n2 + j] += matrix1[i * n1 + k] * matrix2[k * n2 + j];
            }
        }
    }
}

int main(int argc, char *argv[]) {

    int index = 1;

    // Read dimensions of first matrix
    int m1 = atoi(argv[index++]);
    int n1 = atoi(argv[index++]);

    // Read elements of first matrix
    int *matrix1 = (int *)malloc(m1 * n1 * sizeof(int));
    for (int i = 0; i < m1 * n1; i++) {
        matrix1[i] = atoi(argv[index++]);
    }

    // Read dimensions of second matrix
    int m2 = atoi(argv[index++]);
    int n2 = atoi(argv[index++]);


    // Read elements of second matrix
    int *matrix2 = (int *)malloc(m2 * n2 * sizeof(int));
    for (int i = 0; i < m2 * n2; i++) {
        matrix2[i] = atoi(argv[index++]);
    }

    // Allocate memory for the result matrix
    int *result_matrix = (int *)malloc(m1 * n2 * sizeof(int));

    // Multiply matrices
    multiply_matrices(matrix1, m1, n1, matrix2, m2, n2, result_matrix);

    // Print result matrix
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d", result_matrix[i * n2 + j]);  // Print the element
            if (j < n2 - 1) {
                printf(" ");  // Print a space only if it's not the last element in the row
            }
        }
        printf("\n");
    }
    return 0;
}
