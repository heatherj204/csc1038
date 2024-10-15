#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Player Player;
typedef struct Date Date;
typedef struct Name Name;
typedef struct DOB DOB;

struct DOB
{
	int day;
	int month;
	int year;
};

struct Name
{
	char firstName[30];
	char lastName[30];
};


struct Player //Structure type definition
{
  Name name;   //the member name is an instance of the structure Name
  int goal_scored;
  char position[5];
  float price;
  DOB date_of_birth;  //the member date_of_birth is an instance of the structure DOB
};

int main(int argc, char*argv[]){
    Player player1; //Declare a new instance of Player

    strcpy(player1.name.firstName, "Cristiano");
    strcpy(player1.name.lastName, "Ronaldo");
    player1.goal_scored = 500;
    player1.price = 100;
    player1.date_of_birth.day = 5;
    player1.date_of_birth.month = 2;
    player1.date_of_birth.year = 1985;

    printf("player date of birth: %d-%d-%d\n", player1.date_of_birth.day, player1.date_of_birth.month, player1.date_of_birth.year);

    Player player2; //Declare another instance of Player
    strcpy(player2.name.firstName, "im");
    strcpy(player2.name.lastName, "player2");
    //player2.name = player1.name;  //Yes, possibly the two players have the same name...
    player2.date_of_birth = player1.date_of_birth; //... and the same date of birth as well!

    printf("%s %s's date of birth: %d-%d-%d\n", player2.name.firstName, player2.name.lastName, player2.date_of_birth.day, player2.date_of_birth.month, player2.date_of_birth.year);
    return 0;
}