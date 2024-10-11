/*
    Labsheet 5, Task 1
    Name: lab5-cal-everything.c
    Author: Heather Johnston
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* prototypes of the functions */
float sum(float, float);
float product(float, float);
float difference(float, float);
float division(float, float);
float power(float, float);
float naturalLog(float, float);

int main(int argc, char*argv[])
{
	float a = atof(argv[1]);// Initial value for a
	float b = atof(argv[2]);// Initial value for b
	float result = 0;// Storage for results
	
	/* Function pointer declaration */
	float (*pfunction)(float, float);

	pfunction = sum;// points to function sum()
	result = pfunction(a, b);// Call sum() through pointer
	printf("%.2f\n", result);

	/* calls the difference() function through pointer */
	pfunction = difference;
	result = pfunction(a, b);
	printf("%.2f\n", result);

	/* calls the product() function through pointer */
	pfunction = product;
	result = pfunction(a, b);
	printf("%.2f\n", result);

	/* calls the division() function through pointer */
	pfunction = division;
	result = pfunction(a, b);
	printf("%.2f\n", result);

	/* calls the power() function through pointer */
    pfunction = power;
    result = pfunction(a, b);
    printf("%.2f\n", result);

	/* calls the naturalLog() function through pointer */
    pfunction = naturalLog;
    result = pfunction(a, b);
    printf("%.2f\n", result);

    return 0;
}

float sum(float x, float y){
	return x + y;
}

float product(float x, float y){
	return x * y;
}

float difference(float x, float y){
	return x - y;
}

float division(float x, float y){
	return x / y;
}

float power(float x, float y){
	return pow(x, y);
}

float naturalLog(float x, float y){

	return log(y) + log(x);
}