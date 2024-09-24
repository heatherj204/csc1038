/*
What is a string?
    - A sequence of charachters or symbols between a pair of double quote characters
    - Each character has a decimal value in ASCII
*/
#include <stdio.h>
int main(){
    // declairing a string
    char my_ful_name[25] = "Heather Johnston";

    // constant string
    const char message[] = "this is a constant string and it cannot be modified";

    /* counting the lenght of a string*/
    char str[] = "the brown fox jumed over the lazy dog";
    unsigned int count = 0;

    while (str[count] != '\0')
    {
        ++count;
    }

    // how to get a string input from keyboard
    char my_name[25];
    printf("Input your name from keyboard: ");
    fgets(my_name, sizeof(my_name), stdin);
    printf("Your name is: %s\n", my_name);

    int age;
    printf("Input your name from keyboard: ");
    scanf("%d", &age);
    printf("Your age is: %d\n", &age);

}