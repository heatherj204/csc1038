/*
    Labsheet 3, Task 8
    Name: lab3-leap-year.c
    Author: Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>

/* This function will test to see if the year is a leap year and if so it will print it*/
int leapYears(int start, int end){
    for (int year = start; year <= end; year++)
    {
        if ((year % 4 == 0 && year % 100 != 0) ||(year % 400 == 0)){
            printf("%d\n", year);
        }
    }
    return 0;

}

int main(int argc, char*argv[]){
    int start, end;

    // Getting the start and end year from the command line
    start = atoi(argv[1]);
    end = atoi(argv[2]);

    /* Calling the functio to test for leap years based on the start and end year given*/
    leapYears(start, end);

    return 0;
}