/*
    Labsheet 6, Task 2
    Name: lab6-sort-countries.c
    Author: Heather Johnston
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* creating struct for countries*/
typedef struct
{
    char name[50];
    char city[50];
    float population;
    int size;
}country;

/* function prototypes */
void createCountry(country *countries, char*, char*, char*, char*);
void sortCountries(country countries[], int count);
void printSortedCountries(country countries[], int count);


int main(int argc, char* argv[]){
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n"); // printing the first header line
    int amountCountries = (argc - 1) / 4;   // getting the amout of countries
    country countries[amountCountries];  // decalring an array of countries
    int cCount = 0;

    /* passes over command line and calls function to create the country */
    for (int i = 1; i < argc; i+=4){
        createCountry(&countries[cCount], argv[i], argv[i + 1], argv[i + 2], argv[i + 3]);
        cCount++;
    }

    /* calling the sorting function */
    sortCountries(countries, amountCountries);

    /* calling the printing function */
    printSortedCountries(countries, cCount);

    return 0;
}

void createCountry(country *countries, char*name, char*city, char*population, char*size){
    strcpy(countries->name, name);
    strcpy(countries->city, city);
    countries->population = atof(population);
    countries->size = atoi(size);
}

/* sorts the countries */
void sortCountries(country countries[], int count){
    for (int i = 0; i < count -1; i++){
        for (int j = 0; j < count - 1 - i; j++){
            if (countries[j].population < countries[j + 1].population){
                country temp = countries[j];
                countries[j] = countries[j + 1];
                countries[j + 1] = temp;
            }
        }
    }
}

/* prints out the sorted countries */
void printSortedCountries(country countries[], int cCount){
    for (int i = 0; i < cCount; i++){
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n",countries[i].name,countries[i].city, countries[i].size, countries[i].population);
    }
}