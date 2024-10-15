#include <stdio.h>
#include <stdlib.h>

typedef struct Player Player; //Define Player as a type name

struct Player //Structure type definition
{
  char name[30];
  int goal_scored;
  char position[5];
  float price;
};

int main(int argc, char*argv[])
{
	Player player1 = {"Ronaldo", 500, "ST", 75.5}; //define a new instance of Player with initialised values
	Player *pPlayer1 = NULL;   //Declare the pointer
	pPlayer1 = &player1;  //Assign the pointer to the address of player1

    /* both of he print statments do the same but the second on is better in terms of readability and intuituvity*/
    printf("Player name: %s\n", (*pPlayer1).name);
    printf("Player name: %s\n", pPlayer1->name);

    return 0;
}