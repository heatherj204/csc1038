#include <stdio.h>
#include <stdlib.h>

int main(){

    int number = 99;
    int number2 = 100;

    printf("The value of number: %d\n", number);
    printf("The address of number is: %p\n", &number);

    int *pnumber; // while you ca just name the pointer the same as the variable that it is a pointer to, it is good pratice to give it a prefix to show that it is a pointer

    pnumber = &number;
    printf("The value of the pointer pnumber to store number is: %p\n", pnumber);

    pnumber = &number2;
    printf("The value of the pointer pnumber to store number is: %p\n", pnumber);
}