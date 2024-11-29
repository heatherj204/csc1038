/*
    Author: Heather Johnston
    Date: 28/11/2024
    Description: This program will take in an array of integers. Thr programm will print out the most frequent interger from this array. This program will make use of linked list and dynamic memory allocation to complete this task
*/

//Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>




//Struct for each node and data
typedef struct Node Node;

struct Node{
    int value;
    Node *next;
};

//Function prototypes
Node* getNode(int n, char* argv[]);
void printMost(Node *start);


//Main function
int main(int argc, char *argv[]){

    //Finding the length of the array
    int n = argc - 1;

    //Setting the start of the list to be null
    Node *start = NULL;

    //Calling function to get each node of the list
    start = getNode(n, argv);

    //Printing the most frequent value
    printMost(start);
    return 0;
}


//Function implimentation
Node* getNode(int n, char* argv[]){
    Node *curr, *first;

    //Dynamically allocating memory for the first node
    first = (Node*)calloc(1, sizeof(Node));

    curr = first;

    //Setting the value of the first node  from the command line
    curr->value = atoi(argv[1]);

    //Creating and filling in data for each node
    for (int i = 1; i < n; i++){
        curr->next = (Node*)calloc(1, sizeof(Node));
        curr = curr->next;
        curr->value = atoi(argv[i + 1]);
    }
    //As this is the last node in the linked list there will be no pointer to the next node
    curr->next = NULL;
    return first;
}

void printMost(Node *start){
    Node *p = NULL;
    // int freq = 0;
    int mostFreq = 0;
    for (p = start; p != NULL; p = p->next){
        //Setting freq here so that i will go back to 0 after a completion of the inner for loop
        int freq = 0;
        for(Node *j = p; j != NULL; j = j->next){
        // printf("%d\n", p->value);
            //If the value of j (the node that is being changed every loop)is the same as the value of p (the node that stay the same until the outer for loop runs) then there is a 1 added to the frequency variable
            if (j->value == p->value){
                freq++;
            }
        //After every full cycle  the freq is checked to see if we have found a new most freq value
        if (freq > mostFreq){
            mostFreq = freq;
        }
        }
    }
    //The mostFreq value is printed
    printf("%d\n", mostFreq);

}