// Includes
#include <stdio.h>
#include <stdlib.h>


// Struct for student information
typedef struct Student Student;
struct Student
{
    char name[50];
    char college[50];
    int age;
    float grade;
};

// Function prototypes
// Function for parsing information into the struct
Student getInput(Student student);
// Void function for printing information
void printStudent(Student student);

// Defining file name
// #define FILE_NAME "studentBinary.bin"

// Main function
int main(int argc, char* argv[]){

    Student student;
    Student studentInfo = getInput(student);
    printStudent(studentInfo);

    return 0;
}

// Functions goes below here

// Parse data function
Student getInput(Student student){
    FILE *pFile = NULL;
    // Setting the file name
    char *fileName = "studentBinary.bin";
    pFile = fopen(fileName, "rb");

    // Exit the program if the open operatin did not work correctly
    if (!pFile){
        printf("Error opening %s for reading. Program terminated.\n", fileName);
        exit(1);
    }

    // Defining temp variables for length of name and college
    int namelen;
    int collegelen;

    // Start reading the file

    // Get the student name and set it to the length got from the temp namelen varaiable
    fread(&namelen, sizeof(int), 1, pFile);
    fread(student.name, sizeof(char), namelen, pFile);

    // Get the student college and set it to the lenth got from the temp collegelen variable
    fread(&collegelen, sizeof(int), 1, pFile);
    fread(student.college, sizeof(char), collegelen, pFile);

    // Get the student age
    fread(&student.age, sizeof(int), 1, pFile);

    // Get the student grade
    fread(&student.grade, sizeof(float), 1, pFile);

    // Close the file
    fclose(pFile);

    // Returning the student information
    return student;
}
// Print data function
void printStudent(Student student){
    printf("Name: %s\n", student.name);
    printf("College: %s\n", student.college);
    printf("Age: %d\n", student.age);
    printf("Grade: %.2f\n", student.grade);
}