
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* checkSymetric(char*);

int main(int argc, char* argv[]){
    char* word = argv[1];
    printf("%s", checkSymetric(word)) ;

    return 0;
}

char* checkSymetric(char *word){
    int length = strlen(word);
    int left = 0;
    int right = length - 1;
    while (left < right){
        if (word[left] != word[right]){  // comparing each charachter against eachother
            return "no\n";
        }
        left ++;
        right --;
    }
    return "yes\n";
}