/*
 rugby
 author Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    // initilising the variables
    int try;
    int conversion;
    int penalty;
    int drop_goal;

    // getting the values from the command line
    try = atoi(argv[1]) * 5;
    conversion = atoi(argv[2]) * 2;
    penalty = atoi(argv[3]) * 3;
    drop_goal = atoi(argv[4]) * 3;

    // printing the final score
    printf("%d\n", try+conversion+penalty+drop_goal);
    return 0;
}