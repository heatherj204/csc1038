/*
 rugby-further
 author Heather Johnston
 */

// includes
#include <stdio.h>
#include <stdlib.h>

// finction that will retun the pooints got based on type and how many
int Totals(int amount, int point){
    return amount * point;
}

int main(int argc, char * argv[]){
    // defining vars for points
    int try, conversion, penalty, drop_goal;
    // defining vars for user inputs
    int usr_try, usr_conversion, usr_penalty, usr_drop_goal;
    // defining vars for total points
    int try_total, conversion_total, penalty_total, drop_goal_total;
    // defining var for total score
    int totalScore;

    // setting the set points givin for each score type
    try = 5;
    conversion = 2;
    penalty = 3;
    drop_goal = 3;

    // getting the user inputs
    printf("Input the following values: Try, Conversion, Penalty, Drop Goal:\n");
    scanf("%d", &usr_try);
    scanf("%d", &usr_conversion);
    scanf("%d", &usr_penalty);
    scanf("%d", &usr_drop_goal);

    // exiting the program if user inputs negitive data
    if (usr_try < 0 || usr_conversion < 0 || usr_penalty < 0 || usr_drop_goal < 0){
        printf("Values entered cannot be negitive!\n");
        return 0;
    }

    // calling the total function to retun the totals
    try_total = Totals(usr_try, try);
    conversion_total = Totals(usr_conversion, conversion);
    penalty_total = Totals(usr_penalty, penalty);
    drop_goal_total = Totals(usr_drop_goal, drop_goal);

    // calculating the final score
    totalScore = (try_total + conversion_total + penalty_total + drop_goal_total);

    printf("The total score for this match was: %d\n", totalScore);

    return 0;
}