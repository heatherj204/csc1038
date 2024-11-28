#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;              // Data part
    struct Node* next;     // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If list is empty, new node becomes the head
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) { // Traverse to the end of the list
        temp = temp->next;
    }
    temp->next = newNode; // Link the new node at the end
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp == NULL) return;

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head as NULL

    // Insert elements into the linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Linked list: ");
    printList(head);

    // Delete a node
    deleteNode(&head, 20);
    printf("After deletion of 20: ");
    printList(head);

    return 0;
}

/*

The use of the double pointer (**) in the functions like insertAtEnd() and deleteNode() in the linked list implementation is crucial for manipulating the head pointer of the linked list directly. Here's why it's used and what it does:

Why Double Pointer (**)?
A single pointer (*) allows you to pass the address of a node, but if you need to modify the pointer that points to the head node itself (i.e., update the starting point of the list), you need a double pointer (**). This is because changes to a single pointer inside a function are local to that function and do not reflect outside. Using a double pointer ensures the original pointer (outside the function) is modified.

Key Scenarios for Using **
1. Modifying the Head Pointer
When the head node of the linked list changes (e.g., inserting the first node or deleting the head node), you need to update the head pointer itself. A double pointer allows the function to modify the actual head pointer in the caller.

For example:
*/
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // Update the actual head pointer
        return;
    }
    // Traverse and link as usual
}
/*
If you passed a single pointer (*head), this would only update a local copy of head in the function.

2. Maintaining Efficiency
With a double pointer, you avoid returning the updated pointer from the function, which can simplify function calls and improve efficiency when modifying the linked list.

Analogy
Think of a pointer (*) as the key to a door. A double pointer (**) is like a copy of the key to the door. If you need to change the lock on the door (change where the pointer points), you need the copy of the key (the address of the pointer).

Why Not Always Use a Single Pointer?
Using a single pointer is sufficient for operations that don't modify the head pointer, such as traversing or printing the list. However, for operations that can potentially alter the head pointer (like insertion at the start, or deletion of the head node), you must use a double pointer.
Example Without Double Pointer (Incorrect Behavior)
If we didn't use ** for insertAtEnd():

c
Copy code

*/