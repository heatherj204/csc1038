/*
 convert-units
 author Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    // initilising the variable: cm
    int cm = 0;
    // getting the value of the variable from the command line
    cm = atoi(argv[1]);
    // setting the varaible of cmInInch
    float cmInInch = 2.54;
    float inches = cm / cmInInch;
    //printing out the conversion to two decimal places if needed
    printf("%.2f\n", inches);
}
