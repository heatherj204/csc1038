/*
    Labsheet 11, Task 1
    Name: lab11-load-binary.c
    Author: Heather Johnston
*/
// include neccessary libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define a global variable for the binary file name
#define FILE_NAME "studentBinary.bin"

// define structs
typedef struct Student Student;
// student structure
struct Student {
    char name[50];
    char college[50];
    int age;
    float grade;
};

// function prototypes
Student parseStudent(Student student);
void outputStudent(Student student);

// main function
int main(int argc, char*argv[])
{
    Student student;
    Student parsedStudent = parseStudent(student);
    outputStudent(parsedStudent);

    return 0;
}

// Function implementation
Student parseStudent(Student student)
{
    FILE *pFile = NULL;
    // Open a file with read-binary mode
    pFile = fopen(FILE_NAME, "rb");
    if (!pFile)
    {
        printf("Error opening file for writing\n");
        exit(1);
    }

    // Define temp variable
    int nameLen, collegeLen;

    // Start reading information
    fread(&nameLen, sizeof(int), 1, pFile);
    // Use elngth to get the name
    fread(student.name, sizeof(char), nameLen, pFile);
    // and so on...
    fread(&collegeLen, sizeof(int), 1, pFile);
    fread(student.college, sizeof(char), collegeLen, pFile);
    fread(&student.age, sizeof(int), 1, pFile);
    fread(&student.grade, sizeof(float), 1, pFile);

    // close the file
    fclose(pFile);

    // Return the student struct with data
    return student;
}

void outputStudent(Student student)
{
    // Output
    printf("Name: %s\n", student.name);
    printf("College: %s\n", student.college);
    printf("Age: %d\n", student.age);
    printf("Grade: %.2f\n", student.grade);
}