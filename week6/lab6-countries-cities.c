/*
    Labsheet 6, Task 3
    Name: lab6-countries-cities.c
    Author: Heather Johnston
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* city struct */
typedef struct
{
    char name[50];
    float size;
}City;


/* country struct */
typedef struct
{
    char name[50];
    City cities[3];
}Country;

/* function prototypes */
int parse_input(int argc, char *argv[], Country countries[], int cCount);
char* biggestCity(Country *country);
void printCity(Country countries[], int count);


int main(int argc, char* argv[]){
    /* get the amount of countries */
    int cCount = (argc - 1) / 7;

    /* giving a max size to countries*/
    Country countries[cCount];

    /* call function to parse input into array */
    parse_input(argc, argv, countries, cCount);

    /* calling the print function */
    printCity(countries, cCount);

    return 0;
}

int parse_input(int argc, char *argv[], Country countries[], int count){
    int index = 1; // reads from adrgv[1]
    for (int i = 0; i < count; i++){
        strcpy(countries[i].name, argv[index]);
        index++;


        /* copy the cities and their sizes */
        for (int j = 0; j < 3; j++){
            strcpy(countries[i].cities[j].name, argv[index]);
            index++;
            countries[i].cities[j].size = atof(argv[index]);
            index++;
        }
    }
}

char* biggestCity(Country *country){
    /* setting the first city in array innitally to be biggest */
    float size = country->cities[0].size;
    char *city = country->cities[0].name;

    for (int j = 0; j < 3; j++){
        /* checking the size of the next cities to see if bigger then the current largest city */
        if (country->cities[j].size > size){
            size = country->cities[j].size;
            city = country->cities[j].name;
        }
    }
    /* returns the largest city to the print function */
    return city;
}

void printCity(Country countries[], int count){
    for (int i = 0; i < count; i++){
        char *city = biggestCity(&countries[i]);     // calls function to get the biggest city
        printf("%s: %s\n", countries[i].name, city);
    }
}