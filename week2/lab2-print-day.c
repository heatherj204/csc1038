/*
    Labsheet 2, Task 5
    Name: lab2-print-day.c
    Author: Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    // creating an array that had a max of 7 strings each with a max of 10 charschters
    char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int dayEntered = atoi(argv[1]);
    // Prints the day
    printf("%s\n", days[dayEntered - 1]);

    return 0;
}