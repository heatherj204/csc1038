/*
    Labsheet 9, Task 5
    Name: lab9-student.c
    Author: Heather Johnston
*/

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct definition for Student
typedef struct {
    char name[20];
    char programme[20];
    float grade;
} Student;

//Function prototypes
void parseInput(Student *students, char *argv[], int studentCount);
void displayStudents(Student *students, int studentCount);

int main(int argc, char *argv[]) {
    int studentCount = (argc - 1) / 3;
    int initialSize = 2;

    //Allocate memory for initial two students
    Student *students = (Student *)malloc(initialSize * sizeof(Student));

    //Reallocate memory if more than two students are inputted
    if (studentCount > initialSize) {
        students = (Student *)realloc(students, studentCount * sizeof(Student));
    }

    //Parse the input and store in the student array
    parseInput(students, argv, studentCount);

    //Display the student information
    displayStudents(students, studentCount);

    //Free the allocated memory
    free(students);

    return 0;
}

//Function to parse the command line input and store it in the student array
void parseInput(Student *students, char *argv[], int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        strcpy(students[i].name, argv[i * 3 + 1]);
        strcpy(students[i].programme, argv[i * 3 + 2]);
        students[i].grade = atof(argv[i * 3 + 3]);
    }
}

//Function to display student information
void displayStudents(Student *students, int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        printf("%s, %s, %.2f\n", students[i].name, students[i].programme, students[i].grade);
    }
}
