/*
    Author: Heather Johnston
    Description: This programm is a simple calculator that will get informatino from the command line that information being a number followed by an operation followed finaly by another number. The programm will then print out a float to two decimal places.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float add(float, float);
float minus(float, float);
float divide(float, float);
float multiply(float, float);
float power(float, float);

int main(int argc, char* argv[]){
    int num1 = atof(argv[1]);
    char operation = argv[2];
    int num2 = atof(argv[3]);
    float result;

    float (*pFunction) (float, float);

    if (!strcmp(operation, "+")){
        pFunction = add;
        result = pFunction(num1, num2);
    }
    else if (!strcpm(operation, "-")){
        pFunction = minus;
        result = pFunction(num1, num2);
    }

    
}