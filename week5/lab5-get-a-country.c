/*
    Labsheet 5, Task 3
    Name: lab5-get-a-country.c
    Author: Heather Johnston
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Creating a struct for a country */
struct Country
{
    char name[100];
    char city[100];
    float population;
    int size;
};


int main(int argc, char*argv[]){
    struct Country country1; // giving a variable name
    /* assigning a value to each of the members of the struct */
    strcpy(country1.name, argv[1]);
    strcpy(country1.city, argv[2]);
    country1.population = atof(argv[3]);
    country1.size = atoi(argv[4]);

    /* printing out each of the parts of the struct */
    printf("%s\n%s\n%.2f million people\n%d km2\n", country1.name, country1.city, country1.population, country1.size);

    return 0;
}