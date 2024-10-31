/*
Function: Program receives an array of integers and the length being even.
Sorts the list in ascending order then finds the 2 middle most values

Solution: The bubble function is a bubble sort sorting algorithm and this
will be used to sort the array of integers.
The swap function will be used to swap the addresses of 2 different values
Mid_numbers will be used to find and print our middle most values
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void mid_numbers(int *array, int length);
int bubble(int *array, int length);
void swap(int *a, int *b);

int main(int argc, char * argv[])
{
    // Size of the array which will hold all the command line arguments
    int arg_array[argc - 1];
    // Length of the wanted command line integers
    int length = argc - 1;
    int j = 0;
    // Loop turns command line arguments integers and adding them to array
    for(int i = 1; i < argc; i++)
    {
        *(arg_array + j) = atoi(argv[i]);
        j++;
    }
    bubble(arg_array, length);
    mid_numbers(arg_array, length);
    return 0;
}

// Swapping address a with address b
void swap(int *a, int *b)
{
    // temp is our temporary variable
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Here we bubble sort our array of integers in terms of ascending order
// Give function array and length of array
int bubble(int *array, int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < (len - 1); j++)
        {
            if(*(array + j) > *(array + j + 1))
            {
                // Calling function (swap) will swap the addresses of the selected integers
                swap(&*(array + j), &*(array + j + 1));
            }
        }
    }
    return 0;
}

// Function prints out middle integers
void mid_numbers(int *array, int length)
{
    int first_mid;
    int second_mid;
    int mid_index = length / 2;
    first_mid = *(array + mid_index - 1);
    second_mid = *(array + mid_index);
    printf("%d\n%d\n", first_mid, second_mid);
}