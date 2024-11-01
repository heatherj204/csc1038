/*
    Author: Heather Johnston
    Date: 31/10/2024

    Description: This program is givin an array of numbers fro mthe command line. then the program has to calcule what the max differrence is from the smallest number to the largest numbre
*/

/* includes needed for this program */
#include <stdio.h>
#include <stdlib.h>

void sort(int, char*);
int findDiff(int, char*);


int main(int argc, char* argv[]){
    int length = argc - 1;  //getting length of the array
    char numbers[length];   //setting the array with a max length
    int diff; // defining the variable for holding the difference

    /* this loop goes over all elements in the command line added them to the array*/
    for(int i = 0; i < length; i++){
        numbers[i] = atoi(argv[i + 1]);
    }

    sort(length, numbers);  // calling the sorting function
    diff = findDiff(length, numbers);   // calling the findDiff function to get the difference
    printf("%d\n", diff);

    return 0;
}
/* this function sorts the array via bubble sort so the smallest number is first and the biggest number is last  */
void sort(int length, char* numbers){
    for (int i = 0; i < length; i++){
        for (int j = i + 1; j < length; j++){
            if (numbers[i] > numbers[j]){
                int temp;
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}
/* this function finds the difference bweteen the max and minimum numbers*/
int findDiff(int length, char* numbers){
    int minNum = numbers[0];
    // printf("%d\n", minNum);
    int maxNum = numbers[length - 1];
    // printf("%d\n", maxNum);
    int diff = maxNum - minNum;
    return diff;
}
