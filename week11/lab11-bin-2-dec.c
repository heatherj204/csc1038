/*
    Labsheet: 11, Task: 3
    Task: lab11-bin-2-dec.c
    Author: Heather Johnston
*/

// Inclues
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "paragraph.txt"
#define MAX 200

// Function prototypes
void parseNumbers(char*argv[], int *binNums, int length);
int binToDec(int *binNums, int length);
int power(int x, int y);

// Main function
int main(int argc, char*argv[])
{
    int length = argc - 1;
    if (length > 8)
    {
        printf("Too many binary digits entered.\n");
        exit(0);
    }
    int binNums[8];

    parseNumbers(argv, binNums, length);
    int result = binToDec(binNums, length);
    printf("%d\n", result);

    return 0;
}

void parseNumbers(char*argv[], int *binNums, int length)
{
    for (int i = 0; i < length; i++)
    {
        char* curr = argv[i + 1];
        if (strcmp(curr, "0") != 0 && strcmp(curr, "1") != 0)
        {
            printf("Only digits 1 and 0 are permitted.\n");
            exit(0);
        }
        // Convert to int
        binNums[i] = atoi(curr);
    }
}

int binToDec(int *binNums, int length)
{
    int res = 0;
    // Iterate through all binary numbers
    for (int i = 0; i < length; i++)
    {
        // Add the calculated power to the result
        res += binNums[i] * power(2, length - i - 1);
    }
    // Return decimal number
    return res;
}

int power(int x, int y)
{
    // Case for y = 0
    if (y == 0) { return 1; }

    int res = 1;
    for (int i = 0; i < y; i++)
    {
        // Multiply every component by x
        res *= x;
    }
    return res;
}