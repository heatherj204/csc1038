/*
    Author: Heather Johnston
    Date: 31/10/2024

    Description: You are developing a software to manage an inventory for an online store. Each product in the inventory contains the following information:
    Product Name: a string (maximum of 20 characters)
    Stock: an unsigned integer representing the number of items available
    Price: a floating-point number for the price per item
    Discount: a binary value (1 = discount available, 0 = no discount)
*/

/* libararies needed for this program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* creating a struct for the inventory items */
typedef struct
{
    char name[20];
    int stock;
    float price;
    char discount[20];
}inventoryInfo;

/* function prototypes */
void createInventory(inventoryInfo *inventoryItem, char*, char*, char*, char*);
void printInventory(inventoryInfo inventoryItem[], int count);

int main(int argc, char* argv[]){
    int differentInventory = (argc - 1) /4; //getting the amount of differnt inventory types
    int inventoryCount = 0;

    inventoryInfo inventoryItem[differentInventory]; // declaring an array of inventory

    /* this for loop gooes over the data in the command line and parses it to function to create the struct */
    for(int i = 1; i < argc; i+=4){
        createInventory(&inventoryItem[inventoryCount], argv[i], argv[i + 1], argv[i + 2], argv[i + 3]);
        inventoryCount++;
    }
    printInventory(inventoryItem, inventoryCount); // calling the print function to print out each item and its info

    return 0;
}

void createInventory(inventoryInfo *inventoryItem, char*name, char*stock, char*price, char*discount){
    strcpy(inventoryItem->name, name);  // adding the name to item
    inventoryItem->stock = atoi(stock); // adding stock amount to item
    inventoryItem->price = atof(price); // adding price to item
    /* checks to see if the item is discounted */
    if (atoi(discount) == 1){
        strcpy(inventoryItem->discount, "Discounted");
    }
    else{
        strcpy(inventoryItem->discount, "No Discount");
    }
}

void printInventory(inventoryInfo inventoryItem[], int count){
    for(int i = 0; i < count; i++){
        printf("%s,%d,%.2f,%s\n", inventoryItem[i].name,inventoryItem[i].stock,inventoryItem[i].price,inventoryItem[i].discount);
    }
}