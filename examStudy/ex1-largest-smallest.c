

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float largest(int, char*[]);
float smallest(int, char*[]);

int main(int argc, char *argv[]){
    float result;
    float (*pfunction)(int, char*[]);
    char *sorting = argv[1];
    //strcpy(argv[2], sorting);
    //printf("Sorting: %s\n", sorting);
    if (strcmp(sorting, "largest") == 0){
        pfunction = largest;
        printf("%.2f\n", pfunction(argc, argv));
    }
    else if (strcmp(sorting, "smallest") == 0){
        pfunction = smallest;
        printf("%.2f\n", pfunction(argc, argv));
    }
    return 0;
}

float largest(int argc, char* argv[]){
    int length = argc - 2;
    float numbers[length];
    float largest = atof(argv[2]);
    for (int i = 0; i < length; i++){
        numbers[i] = atof(argv[i + 2]);
        //printf("%.2f\n", numbers[i]);
        if (numbers[i] > largest){
            largest = numbers[i];
        }
    }
    return largest;
}

float smallest(int argc, char* argv[]){
    int length = argc - 2;
    float numbers[length];
    float smallest = atof(argv[2]);
    for (int i = 0; i < length; i++){
        numbers[i] = atof(argv[i + 2]);
        //printf("%.2f\n", numbers[i]);
        if (numbers[i] < smallest){
            smallest = numbers[i];
        }
    }
    return smallest;
}