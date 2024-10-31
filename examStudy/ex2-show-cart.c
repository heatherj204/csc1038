#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List List;
struct List {
    char *item[20];
    int amount[100];
    float price[100];
    int promotion[100];
};

struct List sale_nosale(char *arr[], int len);
void sale(char *arr[], int len);

/* main function */
int main(int argc, char* argv[]) {
    char *arr[argc - 1];
    int count = 0;
    for (int i = 1; i < argc; ++i, ++count) {
        arr[count] = argv[i];
    }
    sale(arr, count);
    return 0;
}

void sale(char *arr[], int len) {
    // Initializing the struct
    List items;
    // Assigning the info to the struct
    items = sale_nosale(arr, len);
    // Printing out the info by looping
    for (int i = 0; i < len / 4; ++i) {
        if (items.promotion[i] == 1) {
            printf("%s,%d,%.2f,On Sale\n", items.item[i], items.amount[i], items.price[i]);
        } else {
            printf("%s,%d,%.2f,No Sale\n", items.item[i], items.amount[i], items.price[i]);
        }
    }
}

/* Assigning info to struct List */
struct List sale_nosale(char *arr[], int len) {
    List all_items;
    int count = 0;
    int index = 0;
    for (int i = 0; i < len; ++i) {
        if (count == 4) {
            all_items.item[index] = arr[i - 4];
            all_items.amount[index] = atoi(arr[i - 3]);
            all_items.price[index] = atof(arr[i - 2]);
            all_items.promotion[index] = atoi(arr[i - 1]);
            ++index;
            count = 0;
        } else if (i == len - 1) {
            // I had a -1 error
            all_items.item[index] = arr[i - 3];
            all_items.amount[index] = atoi(arr[i - 2]);
            all_items.price[index] = atof(arr[i - 1]);
            all_items.promotion[index] = atoi(arr[i]);
            ++index;
            count = 0;
        }
        ++count;
    }
    return all_items;
}