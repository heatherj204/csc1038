/*
 circle-area.c
 author Heather Johnston
 */

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions we may need*/

#define PI 3.14 /*Defining PI as a constant*/

/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description:  Takes a single argument and computes area of circle
 */

int main(int argc, char *argv[])
{
/* variable initialisation */
	int radius = 0;
	float area = 0.0;
/* all command-line arguments come in as character strings, so atoi turns them into ints*/
    scanf("%d", &radius);
	// radius = atoi(argv[1]);
    if (radius < 0){
        printf("Radius entered is negitive this will be corrected, radius entered: %i\n", radius);
    }

	radius = radius*radius; /* radius squared */

	area  = radius*PI; /* calculate area of circle */

    /* print to two decimal places*/
    printf ("%.2f\n",area); /* We only want to show only two values to the right of the decimal point*/
    // printf ("%9.2f\n",area); /* We want to set the width of the shown number = 9. If the total number of digits < 9, spaces will be shown before the number*/

    return (0); /* exit correctly*/
} /* end program*/