/*
    Labsheet 6, Task 1
    Name: lab6-find-country.c
    Author: Heather Johnston
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* creating struct for countries*/
typedef struct Country
{
    char name[50];
    char city[50];
    float population;
    int size;
}country;

/* function prototype */
void checkSize(country countries[], int count);
void createCountry(country *countries, char*, char*, char*, char*);

int main(int argc, char* argv[]){
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n"); // printing the first header line
    int amountCountries = (argc -1) / 4;    // getting the amout of countries
    country countries[amountCountries];  // decalring an array of countries
    int cCount = 0;

    /* passes over command line and calls function to create the country */
    for (int i = 1; i < argc; i+= 4){
        createCountry(&countries[cCount], argv[i], argv[i + 1], argv[i + 2], argv[i + 3]);
        cCount++;
    }

    /* calls function to check the size of the country*/
    checkSize(countries, amountCountries);

    return 0;
}

void createCountry(country *countries, char*name, char*city, char*population, char*size){
    strcpy(countries->name, name);
    strcpy(countries->city, city);
    countries->population = atof(population);
    countries->size = atoi(size);
}


void checkSize(country countries[], int count){
    for (int i = 0; i < count; i++){
        if (countries[i].size < 100000){
            printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n",countries[i].name,countries[i].city, countries[i].size, countries[i].population);
        }
    }
}
