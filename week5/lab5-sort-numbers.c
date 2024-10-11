/*
    Labsheet 5, Task 2
    Name: lab5-sort-numbers.c
    Author: Heather Johnston
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void asc(char*, int);
void desc(char*, int);

int main(int argc, char*argv[]){
    int length = atoi(argv[1]);
    char *numbers[length];
    for (int i = 0; i < length; i++){
        numbers[i] = atoi(argv[i + 1]);
        printf("%d\n", atoi(argv[i + 1]));
    }

    char *order = argv[length + 1];

    int (*pfunction)(char*, int);// Function pointer declaration

    if (strcmp(order, "asc") == 0)
    {
        pfunction = asc;
        pfunction(numbers, length);
    }
    else if (strcmp(order, "desc") == 0)
    {
        pfunction = desc;
        pfunction(numbers, length);
    }

    return 0;
}

void asc(char *numbers, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] > numbers[j])
            {
                    int temp;
                    temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
            }
        }
    }
}
void desc(char *numbers, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] < numbers[j])
            {
                    int temp;
                    temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
            }
        }
    }
}



/*
    Workflow:
    - get the lenght (argc[1])
    - create the array with a max size
    - get the order (argc[-1])
    - call the function based on the order (void function as its modifying and array)

    For acs function:
    - 
*/