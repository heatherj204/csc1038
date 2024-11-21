/*
    Labsheet 10, Task 4
    Name: lab10-inside-the-queue.c
    Author: Heather Johnston
*/

//Includes
#include <stdio.h>
#include <stdlib.h>

//Declare typedef of node struct
typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

//Function prototypes
void printLinkedList(Node *start);
void push(Node *start, int newValue);
void findAndInsert(Node *start, int target, int newVal);

//Main function
int main(int argc, char*argv[]){

    int size = 10;
    int nums[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};

    // set the first node manually as its easier in this case
    Node* start = (Node*)calloc(1, sizeof(Node));
    start->value = nums[0];

    // start looping from the second value
    for (int i = 1; i < size; i++){
        push(start, nums[i]);
    }

    // get our values from the command line
    int target = atoi(argv[1]);
    int toInsert = atoi(argv[2]);

    findAndInsert(start, target, toInsert);

    printLinkedList(start);
    return 0;
}

void printLinkedList(Node *start)
{
    Node *node = NULL;
    //Going through until the end
    for (node = start; node != NULL; node = node->next){
        // print the value
        printf("%d\n", node->value);
    }
}

void push(Node *start, int newValue)
{
    Node* curr = start;

    Node* newNode = (Node*)calloc(1, sizeof(Node));
    newNode->value = newValue;

    // keep going to the next node until it hits NULL (the end)
    while (curr->next != NULL){
        curr = curr->next;
    }

    curr->next = newNode;
}

void findAndInsert(Node *start, int target, int newVal){
    Node *curr = start;
    //Find the position of target
    while (curr->next != NULL && curr ->value != target){
        curr = curr->next;
    }

    Node* newNode = (Node*)calloc(1, sizeof(Node));
    //Update value of new node
    newNode->value = newVal;
    //Set the new node next to original next node
    newNode->next = curr->next;
    //Set current to the new node
    curr->next = newNode;
}