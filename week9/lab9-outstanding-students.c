/*
    Labsheet 9, Task 6
    Name: lab9-outstanding-students.c
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
void averageGrade(Student *students, int studentCount);
void CSCEAboveAverage(Student *students, int studentCount, float average);

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

    //Get the overall average
    averageGrade(students, studentCount);

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

//Function to find the overall average grade then call the function to check the CSCE students grades
void averageGrade(Student *students, int studentCount) {
    float grades = 0;
    int count = 0;
    for (int i = 0; i < studentCount; i++) {
        grades += students[i].grade;
        count++;
    }
    float average = grades / count;

     //Get the CSCE students who are above the average
    CSCEAboveAverage(students, studentCount, average);
    printf("Average grade: %.2f\n", average);
}

//Function to check the grade of all CSCE students and print any student who has a grade that is above average
void CSCEAboveAverage(Student *students, int studentCount, float average){
    for (int i = 0; i < studentCount; i++){
        if ((!strcmp(students[i].programme, "CSCE")) && students[i].grade > average){
            printf("%s, %.2f\n", students[i].name, students[i].grade);
        }
    }
}
