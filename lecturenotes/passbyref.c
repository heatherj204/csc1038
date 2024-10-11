#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(int argc, char*argv[]){
    int a[5] = {5, 4, 3, 2, 1};

    for (int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (a[i] > a[j])
            {
                /* Passing a reference of the array*/
                swap(&a[i], &a[j]);
            }
        }
    }
    /* Printing out the sorted array*/
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *a, int *b)
{
    /* Swappping the numbers */
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
