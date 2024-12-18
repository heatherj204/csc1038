/*
    Author heather johnston
*/

//Inclues
#include <stdlib.h>
#include <stdio.h>

// Struct for node
typedef struct Node Node;

struct Node{
    int value;
    int posX;
    int posY;
    Node *next;
};

//Function prototypes
Node* buildMatrix(int nonZero, int rows, int col, char *argv[]);
void printMatrix(Node *start, int col, int rows);
int printSum(Node *start, int rows, int col);
int getNum(Node *start, int r, int c);

//Main functinon
int main(int argc, char *argv[])
{
    int rows = atoi(argv[1]);
    int col = atoi(argv[2]);
    int nonZero = atoi(argv[3]);

    Node *start = NULL;
    start = buildMatrix(nonZero, rows, col, argv);
    printMatrix(start, col, rows);
    int total = printSum(start, rows, col);
    printf("%d\n", total);
    return 0;
}

//Function implimentations
Node* buildMatrix(int nonZero, int rows, int col, char *argv[]){
    Node *current, *first;

    // Allocating memory for the frist node
    first = (Node*)calloc(1, sizeof(Node));

    current = first;

    // Setting the data for the first node
    current->value = atoi(argv[4]);
    current->posX = atoi(argv[5]);
    current->posY = atoi(argv[6]);

    for (int i = 7; i < nonZero * 4; i = i + 3){
        current->next = (Node*)calloc(1, sizeof(Node));
        current = current->next;
        current->value = atoi(argv[i]);
        current->posX = atoi(argv[i + 1]);
        current->posY = atoi(argv[i + 2]);
    }
    current->next = NULL;
    return first;
}

void printMatrix(Node *start, int col, int rows){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < col; j++){
            int value = getNum(start, i, j);
            printf("%d ", value);
        }
        printf("\n");
    }
}
int getNum(Node *start, int r, int c){
    Node* p = NULL;
    for (p = start; p != NULL; p = p->next){
        if (p->posX == r && p->posY == c){
            return p->value;
        }
    }
    return 0;
}

int printSum(Node *start, int rows, int cols){
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == i){
                sum += getNum(start, i, j);
            }
        }
    }
    return sum;
}