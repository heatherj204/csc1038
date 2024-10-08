/*
    Labsheet 4, Task 4
    Name: lab4-search-sub-string.c
    Author: Heather Johnston
 */

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int startPos(char *line, char *word){
    /* points to where the first occorence happens*/
    char *pPlace = strstr(line, word);
    int start = pPlace - line;
    return start;

}

int endPos(char *line, char *word){
    /* points to where the first occorence happens*/
    char *pPlace = strstr(line, word);
    int start = pPlace - line;
    int end = start + strlen(word) - 1;
    return end;

}
int main(int argc, char *argv[]){
    char *line = argv[1];
    char *word = argv[2];
    /* finds the difference between the two points */
    int start = startPos(line, word);
    /* finds the difference between the points*/
    int end = endPos(line, word);

    printf("%d %d\n", start, end);
    return 0;
}