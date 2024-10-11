/*
    Labsheet 5, Task 5
    Name: lab5-average-population.c
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
    
    /* setting variables */
    int cCount = 0;
    float allPop = 0; // float to store the total population
    for(int i = 1; i < argc; i += 4)
    {
        struct Country country[i]; // updating the size with every loop to allow another country to be added

        /* adding data to the members of the struct */
        country[cCount].name = argv[i];
        country[cCount].city = argv[i + 1];
        country[cCount].size = atoi(argv[i + 3]);
        country[cCount].population = atof(argv[i + 2]);

        allPop += country[cCount].population; // adding to the total population with every loop
        
        /* Printing the country information */
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country[cCount].name, country[cCount].city, country[cCount].size, country[cCount].population);
        cCount++;
    }

    /* Printing out the average population */
    printf("Population average: %.2f\n", (allPop / cCount));

}