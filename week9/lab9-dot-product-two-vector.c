/*
    Labsheet 9, Task 1
    Name: lab9-dot-product-two-vector.c
    Author: Heather Johnston
*/

#include <stdio.h>
#include <stdlib.h>

/* function prototype */
void getVectors(char *argv[], int *vector1, int *vector2, int size);
int dotProd(int *vector1, int *vector2, int size);

int main(int argc, char *argv[]){
    int size = atoi(argv[1]);   //getting the size of the vectors

    /* dynamically allocation the memory for the two vectors */
    int *pVector1 = (int*)calloc(size, sizeof(int));
    int *pVector2 = (int*)calloc(size, sizeof(int));

    getVectors(argv, pVector1, pVector2, size); //calling function to parse data to create the vectors
    int result = dotProd(pVector1, pVector2, size);

    printf("%d\n", result);

    /* freeing memory */
    free(pVector1);
    free(pVector2);
    return 0;
}

void getVectors(char *argv[], int *vector1, int *vector2, int size){
    /* parsing to create the vectors */
    for (int i = 0; i < size; i++){
        vector1[i] = atoi(argv[i + 2]);
        vector2[i] = atoi(argv[i + 2 + size]);
    }
}

int dotProd(int *vector1, int *vector2, int size){
    int result = 0;
    /* getting the dot product for the vectors */
    for (int i = 0; i < size; i++){
        result += (vector1[i] * vector2[i]);
    }
    return result;  //returning the dot product
}
