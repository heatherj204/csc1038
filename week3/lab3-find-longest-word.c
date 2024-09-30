/*
    Labsheet 3, Task 7
    Name: lab3-find-longest-word.c
    Author: Heather Johnston
 */

#include <stdio.h>
#include <string.h>

// Function to find and print the longest word
void findLongestWord(char sentence[]) {
    char *word;
    char longestWord[100] = "";
    int longestLength = 0;
    /* Get each word in the sentenct seperatly by the space*/
    word = strtok(sentence, " ");
    while (word != NULL) {
        int length = strlen(word);
        if (length > longestLength) {
            longestLength = length;
            strcpy(longestWord, word);
        }
        word = strtok(NULL, " ");
    }

    // Print the longest word followed by a newline
    printf("%s\n", longestWord);
}

int main(int argc, char *argv[]) {
    // Call the function to find the longest word
    char sentence[1000];
    strcpy(sentence, argv[1]);
    findLongestWord(sentence);

    return 0;
}
