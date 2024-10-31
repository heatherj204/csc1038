#include<stdio.h>
#include<stdlib.h>

int sumOfArray(int* pNumbers, int length);
int productOfArray(int *pNumbers, int length);

int main(int argc, char*argv[])
{
    int length = argc - 1;
    int *pNumbers = NULL;
    int *pResult = NULL;

    pNumbers = (int*)malloc(length*(sizeof(int)));
    if(!pNumbers)
    {
        //... Code to deal with memory allocation failure, for example:
        printf("Failed to allocate memory!");
        return 0;
    }

    for(int i = 0; i < length; ++i)
    {
        *(pNumbers+i) = atoi(argv[i+1]);
    }

    /*Calculate sum */
    pResult = (int*)malloc(1*(sizeof(int)));
    *pResult = sumOfArray(pNumbers, length);
    printf("Sum of the array is: %d\n", *pResult);
    free(pResult); //Free the memory
    pResult = NULL;

    printf("Now the programing is calculating the product of the array...\n");

    /* Calculate the product */
    pResult = (int*)malloc(1*(sizeof(int)));
    *pResult = productOfArray(pNumbers, length);
    printf("Product of the array is: %d\n", *pResult);
    free(pResult); //Free the memory
    free(pNumbers);
    pResult = NULL;
    pNumbers = NULL;

    return 0;
}

int sumOfArray(int* pNumbers, int length)
{
    int sum = 0;
    for(int i = 0; i < length; ++i)
    {
        sum += *(pNumbers + i);
    }
    return sum;
}

int productOfArray(int *pNumbers, int length)
{
    int product = 1;
    for(int i = 0; i < length; ++i)
    {
        product *= *(pNumbers + i);
    }
    return product;
}