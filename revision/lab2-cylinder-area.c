// Includes
#include <stdlib.h>
#include <stdio.h>
#include  <stdbool.h>

// Defining PI
#define PI 3.1415

// Function prototypes
bool checkInputs(int argc, char *argv[]);
float getArea(int argc, char *argv[]);

// Main function
int main(int argc, char *argv[]){
    if (!checkInputs(argc, argv)){
        return 1;
    }
    float area = getArea(argc, argv);
    printf("%.2f\n", area);
    return 0;

}

// Function for checking values returns false if the values are not able to be computed
bool checkInputs(int argc, char *argv[]){
    bool Ans = true;
    if (argc == 1){
        printf("No input given!\n");
        Ans = false;
    }
    else if (argc == 2){
        printf("Two arguments needed!\n");
        Ans = false;
    }
    else if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0){
        printf("The radious or height cannot be negative!\n");
        Ans = false;
    }
    return Ans;
}

// Function for getting area
float getArea(int argc, char *argv[]){
    float area;
    int rad = atoi(argv[1]);
    int height = atoi(argv[2]);
    area = (2 * PI) * (rad * height) + (2 * PI) * (rad) * (rad);
    return area;
}