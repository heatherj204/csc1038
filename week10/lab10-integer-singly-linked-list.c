/*
    Labsheet 10, Task 1
    Name: lab10-integer-singly-linked-list.c
    Author: Heather Johnston
*/

//Includes
#include <stdlib.h>
#include <stdio.h>

//Declare structure of node
typedef struct Node Node;

struct Node{
    int value;
    Node *next;
};

//Function prototypes
Node* getNode(int n, char* argv[]);
void printNode(Node *start);


int main(int argc, char *argv[]){

    int n = atoi(argv[1]); //Getting the length of the list

    Node *start = NULL;
    start = getNode(n, argv);
    printNode(start);
    return 0;
}

Node* getNode(int n, char* argv[]){
    Node *current, *first;

    first = (Node*)calloc(1, sizeof(Node)); //Allocating memory and creating first node

    current = first; //Setting the current node to the first node

    current->value = atoi(argv[2]); //Setting value for the first node

    //Creating and filling in data for each node
    for (int i = 1; i < n; i++){
        current->next = (Node*)calloc(1, sizeof(Node));
        current = current->next;
        current->value = atoi(argv[i + 2]);
    }
    current->next = NULL; //There is no pointer to the next node as there is no next node
    return first;
}

//This function will display the list of numbers
void printNode(Node *start){
    Node* p = NULL;
    for (p = start; p != NULL; p = p->next){
        printf("%d\n", p->value);
    }
}