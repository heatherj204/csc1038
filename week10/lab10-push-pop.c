/*
    Labsheet 10, Task 3
    Name: lab10-push-pop.c
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
    Node *prev;
};

//Function prototypes
Node* getNode(int n, char* argv[]);
void pop(Node *start);
void push(Node *start, int value);
void printNode(Node *start);


int main(int argc, char *argv[]){

    int n = atoi(argv[1]); //Getting the length of the list

    Node *start = NULL;
    start = getNode(n, argv);
    pop(start);
    pop(start);
    push(start, atoi(argv[argc - 2]));
    push(start, atoi(argv[argc - 1]));
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
    return first;
}
void pop(Node *start){
    Node *pop, *last;
    // First find the end of the list
    for (Node *cur = start; cur != NULL; cur = cur->next){
        pop = cur;
    }
    last = pop;
    pop = pop->prev;
    //Freeing prev
    free(last->next);
    free(last);
    pop->next = NULL;
}

void push(Node *start, int value){
        Node *push, *last;
    //Gets the end of the list
    for (Node *cur = start; cur != NULL; cur = cur->next){
        push = cur;
    }
    //Allocating memory for the new details
    push->next = (Node *)calloc(1, sizeof(Node));
    last = push;
    push = push->next;
    push->prev = last;
    push->value = value;
    push->next = NULL;
}

//This function will display the list of numbers
void printNode(Node *start){
    Node* p = NULL;
    for (p = start; p != NULL; p = p->next){
        printf("%d\n", p->value);
    }
}

