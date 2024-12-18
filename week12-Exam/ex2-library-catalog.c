/*
    Author:Heather Johnston
    Date: 28/11/2024

    Discription
A library catalog contains information about books, including their title, author, and year of publication.

Write a program ex2-library-catalog.c that:

    Accepts the number of books and their details (title, author, and year of publication) as command-line arguments. You can assume that title and author have 100 characters maximum.

    Stores the book details in a linked list using dynamic memory allocation.

    Displays the list of books in the catalog in the format: Title: <title>, Author: <author>, Year: <year> in reverse.

    Accepts a year as a command-line argument and displays all books published after that year. If there is no book found, display: No books found published after <year>.




*/
/*
    Author:Heather Johnston
    Date: 28/11/2024

    Discription:


*/

//Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Declare structure of node
typedef struct Node Node;

struct Node{
    char name[50];
    char author[50];
    int year;
    Node *next;
    Node *prev;
};

//Function prototypes
Node* getNode(int n, char* argv[]);
void printNode(Node *last);
void printYear(int year, Node *last);


int main(int argc, char *argv[]){

    int n = atoi(argv[1]); //Getting the length of the list

    //Getting the year for books published
    int year = atoi(argv[argc - 1]);

    Node *start = NULL;
    start = getNode(n, argv);
    printNode(start);
    printYear(year, start);
    return 0;
}

Node* getNode(int n, char* argv[]){
    Node *current, *first, *prev;

    first = (Node*)calloc(1, sizeof(Node)); //Allocating memory and creating first node

    current = first; //Setting the current node to the first node

    strcpy(current->name, (argv[2])); //Setting value for the first node
    strcpy(current->author, (argv[3]));
    current->year = atoi(argv[4]);
    current->prev = NULL;

    //Creating and filling in data for each node
    for (int i = 4; i < n * 3; i++){
        printf("%d\n", i);
        current->next = (Node*)calloc(1, sizeof(Node));
        prev = current;  //Getting the prev node before moving to the next node
        current = current->next;  //Moving the current pointer to the next node
        //Setting information for the first node
        strcpy(current->name, (argv[i++]));
        printf("%d\n", i);
        strcpy(current->author, (argv[i++]));
        printf("%d\n", i);
        current->year = atoi(argv[i++]);
        printf("%d\n", i);
        current->prev = prev;
    }
    current->next = NULL; //There is no pointer to the next node as there is no next node
    return current;
}

//This function will display the list of numbers
void printNode(Node *last){
    printf("Library Catalog:\n");
    Node* p = NULL;
    for (p = last; p != NULL; p = p->prev){
        printf("Title: %s, Author: %s, Year: %d\n", p->name, p->author, p->year);
    }
}

void printYear(int year, Node *last){
    printf("\nBooks published after %d:\n", year);
    Node* p = NULL;
    for (p = last; p != NULL; p = p->prev){
        if (p->year >= year){
            printf("Title: %s, Author: %s, Year: %d\n", p->name, p->author, p->year);
        }
    }
}

