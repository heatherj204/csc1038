/*
    Author: Heather Johnston
    Date: 31/10/2024

    Description: this program will go over the total value of each item in the inventory. if the item is discounted then a 10% discount is applied to it
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
    int discount;
}inventoryInfo;

/* function prototypes */
void createInventory(inventoryInfo *inventoryItem, char*, char*, char*, char*);
void printValue(inventoryInfo inventoryItem[], int count);

int main(int argc, char* argv[]){
    int differentInventory = (argc - 1) /4; //getting the amount of differnt inventory types
    int inventoryCount = 0;

    inventoryInfo inventoryItem[differentInventory]; // declaring an array of inventory

    /* this for loop gooes over the data in the command line and parses it to function to create the struct */
    for(int i = 1; i < argc; i+=4){
        createInventory(&inventoryItem[inventoryCount], argv[i], argv[i + 1], argv[i + 2], argv[i + 3]);
        inventoryCount++;
    }
    printValue(inventoryItem, inventoryCount); // calling the print function to print out the total value of all stock

    return 0;
}


void createInventory(inventoryInfo *inventoryItem, char*name, char*stock, char*price, char*discount){
    strcpy(inventoryItem->name, name);  // adding the name to item
    inventoryItem->stock = atoi(stock); // adding stock amount to item
    inventoryItem->price = atof(price); // adding price to item
    inventoryItem->discount = atoi(discount);
}

void printValue(inventoryInfo inventoryItem[], int count){
    float total;
    for(int i = 0; i < count; i++){
        if (inventoryItem[i].discount == 0){
            total += (inventoryItem[i].stock) * (inventoryItem[i].price);
        }
        else if (inventoryItem[i].discount == 1){
            total += ((inventoryItem[i].stock) * (inventoryItem[i].price)) * 0.9;
        }
    }
    printf("%.2f\n", total);
}