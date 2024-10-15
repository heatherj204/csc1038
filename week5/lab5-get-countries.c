/*
    Labsheet 5, Task 4
    Name: lab5-get-countries.c
    Author: Heather Johnston
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Creating a struct for a country */
typedef struct Country
{
    char *name;
    char *city;
    float population;
    int size;
} country;



int main(int argc, char*argv[]){


    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n"); // printing out the top line
    int cCount = 0;
    for(int i = 1; i < argc; i += 4)
    {
        struct Country country[i]; // updating the size with every loop to allow another country to be added
        country[cCount].name = argv[i];
        country[cCount].city = argv[i + 1];
        country[cCount].size = atoi(argv[i + 3]);
        country[cCount].population = atof(argv[i + 2]);


        /* Printing the country information */
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country[cCount].name, country[cCount].city, country[cCount].size, country[cCount].population);
        cCount++;
    }
}