/*
    Labsheet 10, Task 2
    Name: lab10-float-doubly-linked-list.c
    Author: Heather Johnston
*/

//Includes
#include <stdlib.h>
#include <stdio.h>

//Declare structure of node
typedef struct Node Node;

struct Node{
    float value;
    Node *next;
    Node *prev;
};

//Function prototypes
Node* getNode(int n, char* argv[]);
void printNode(Node *last);


int main(int argc, char *argv[]){

    int n = atoi(argv[1]); //Getting the length of the list

    Node *start = NULL;
    start = getNode(n, argv);
    printNode(start);
    return 0;
}

Node* getNode(int n, char* argv[]){
    Node *current, *first, *prev;

    first = (Node*)calloc(1, sizeof(Node)); //Allocating memory and creating first node

    current = first; //Setting the current node to the first node

    current->value = atof(argv[2]); //Setting value for the first node
    current->prev = NULL;

    //Creating and filling in data for each node
    for (int i = 1; i < n; i++){
        current->next = (Node*)calloc(1, sizeof(Node));
        prev = current;  //Getting the prev node before moving to the next node
        current = current->next;  //Moving the current pointer to the next node
        current->value = atof(argv[i + 2]);
        current->prev = prev;
    }
    current->next = NULL; //There is no pointer to the next node as there is no next node
    return current;
}

//This function will display the list of numbers
void printNode(Node *last){
    Node* p = NULL;
    for (p = last; p != NULL; p = p->prev){
        printf("%.2f\n", p->value);
    }
}