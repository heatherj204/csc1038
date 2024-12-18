/*
Write a program lab9-dot-product-two-vector.c which accepts the following arguments from the command line. The first argument is the size of two vectors n. The next n arguments are the elements of vector 1, and the last n arguments are the elements of vector 2. The program calculate the dot product of the two vectors and print the result. Note that you are required to find a way to use dynamic memory allocation, i.e. malloc, calloc, realloc and free in this task, also you are encouraged to use function to design the solution.
*/

// Includes
#include <stdlib.h>
#include <stdio.h>

// Function prototypes
void getVectors(char *argv[], int *pVector1, int *pVector2, int n);
int dotProd(int *pVector1, int *pVector, int n);

// Main function
int main(int argc, char *argv[]){
    int n = atoi(argv[1]);

    // Dynamically allocating memory for the vectors
    int *pVector1 = (int*)calloc(n, sizeof(int));
    int *pVector2 = (int*)calloc(n, sizeof(int));
    getVectors(argv, pVector1, pVector2, n);
    int dotProduct = dotProd(pVector1, pVector2, n);
    printf("%d\n", dotProduct);
}

void getVectors(char *argv[], int *pVector1, int *pVector2, int n){
    for (int i = 0; i < n; i++){
        pVector1[i] = atoi(argv[i + 2]);
        pVector2[i] = atoi(argv[i + 2 + n]);
    }
}

int dotProd(int *pVector1, int *pVector2, int n){
    int total;
    for (int i = 0; i < n; i++){
        total += pVector1[i] * pVector2[i];
    }
    return total;
}
