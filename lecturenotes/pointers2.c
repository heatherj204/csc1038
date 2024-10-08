#include <stdio.h>

int main(int argc, char*argv[]){

    int inputArray[3] = {1,2,3};
    int* pFirstElement = &inputArray[0];

    printf("The addres of the first elemnt is: %p\n", pFirstElement); // this gives the addred of the pointer in the memory and NOT the value
    printf("The address obtained from the array name inputArray is: %p\n", inputArray);
    printf("The value of the first element is: %d\n", *pFirstElement); // this gives the value of the pointer and NOT the address
    printf("The addres of the second elemnt is: %p\n", pFirstElement + 1);
    printf("The value of the second element is: %d\n", *(pFirstElement + 1));

    return 0;
}