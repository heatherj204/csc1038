/*
    Labsheet 5, Task 1
    Name: lab5-cal-everything.c
    Author: Heather Johnston
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	float (*pfunction)(float, float);// Function pointer declaration

	pfunction = sum;// points to function sum()
	result = pfunction(a, b);// Call sum() through pointer
	printf("%.2f\n", result);

	pfunction = difference;                  // points to function difference()
	result = pfunction(a, b);                // Call difference() through pointer
	printf("%.2f\n", result);

	pfunction = product;                     // points to function product()
	result = pfunction(a, b);                // Call product() through pointer
	printf("%.2f\n", result);
	pfunction = division;
	result = pfunction(a, b);
	printf("%.2f\n", result);

    pfunction = power;
    result = pfunction(a, b);
    printf("%.2f\n", result);

    pfunction = naturalLog;
    result = pfunction(a, b);
    printf("%.2f\n", result);

    return 0;
}

float sum(float x, float y)
{
	return x + y;
}
float product(float x, float y)
{
	return x * y;
}
float difference(float x, float y)
{
	return x - y;
}
float division(float x, float y)
{
	return x / y;
}
float power(float x, float y)
{
	return pow(x, y);
}
float naturalLog(float x, float y)
{
	return x * (log(y) / log(x));
}