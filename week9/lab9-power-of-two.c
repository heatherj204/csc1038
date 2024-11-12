/*
    Labsheet 9, Task 7
    Name: lab9-power-of-two.c
    Author: Heather Johnston
*/

//Includes
#include <stdlib.h>
#include <stdio.h>

//Function prototypes
int isPower(int num);

int main(int argc, char *argv[]){
    int num = atoi(argv[1]);
    if (isPower(num)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}

//Function returns 1 if the number is a power of two
int isPower(int num){
    if (num & (num - 1)){
        return 0;
    }
    else{
        return 1;
    }
}
