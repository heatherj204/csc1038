// Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Function prototypes
char *getLines(char *fileName);
// Main function
int main(int argc, char *argv[]){

    char *fileName = "paragraph.txt";
    char *longestStr = getLines(fileName);
    int lineLength = strlen(longestStr);
    printf("%d\n%s\n", lineLength, longestStr);

    return 0;
}

// Function implementation rewaq
char *getLines(char *fileName){
    FILE *pFile = NULL;
    pFile = fopen(fileName, "r");
    if (!pFile){
        printf("Error opening %s for reading. Program terminated\n", fileName);
        exit(1);
    }
    // Declare temp variable
    char tempLen[200];
    int longestLen = 0;

    // Allocate memory to hold the longest string
    char *longestStr = (char *)calloc(1, sizeof(char));
    while (fgets(tempLen, sizeof(tempLen), pFile)){
        if (strlen(tempLen) > longestLen){

            // Save line length
            longestLen = strlen(tempLen);
            // Reallocate memory to store the new longest string
            longestStr = realloc(longestStr, longestLen * sizeof(char));
            // Copy the longest string to the temp string value
            strcpy(longestStr, tempLen);
        }
    }
    // Return the longest string
    return longestStr;
}