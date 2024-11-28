#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a student
struct Student {
    char name[50];   // To store the student's name
    char module[50]; // To store the student's module
    int age;         // To store the student's age
    float grade;     // To store the student's grade
};

// Function prototypes
int readStudentsFromFile(char *filename, struct Student **students, int *count);
void printStudentsInfo(struct Student students[], int count);
void freeStudents(struct Student *students);

int main() {
    struct Student *students = NULL; // Dynamically allocated array of students
    int studentCount = 0;            // Number of students in the file

    // Read students from the file
    if (readStudentsFromFile("studentinfo.txt", &students, &studentCount) != 0) {
        fprintf(stderr, "Failed to read students from the file.\n");
        return 1; // Exit with an error code
    }

    // Print all the student information
    printStudentsInfo(students, studentCount);

    // Free allocated memory
    freeStudents(students);

    return 0; // Successful program termination
}

/**
 * Reads student data from a file and dynamically allocates memory for the students.
 * 
 * @param filename The name of the file to read.
 * @param students Pointer to the array of Student structs (to be allocated).
 * @param count Pointer to an integer where the number of students will be stored.
 * @return 0 on success, or a non-zero value on failure.
 */
int readStudentsFromFile(char *filename, struct Student **students, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) { // Check if the file opened successfully
        perror("Error opening file");
        return 1; // Return error code
    }

    // Read the number of students from the first line
    if (fscanf(file, "%d", count) != 1) {
        fprintf(stderr, "Error reading the number of students\n");
        fclose(file);
        return 1; // Return error code
    }

    // Allocate memory for the students
    *students = (struct Student *)malloc(*count * sizeof(struct Student));
    if (*students == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1; // Return error code
    }

    // Read each student's data
    for (int i = 0; i < *count; i++) {
        if (fscanf(file, "%49s %49s %d %f", 
                   (*students)[i].name, 
                   (*students)[i].module, 
                   &(*students)[i].age, 
                   &(*students)[i].grade) != 4) {
            fprintf(stderr, "Error reading data for student %d\n", i + 1);
            free(*students);
            fclose(file);
            return 1; // Return error code
        }
    }

    // Close the file
    fclose(file);
    return 0; // Success
}

/**
 * Prints information for all students.
 *
 * @param students Array of Student structs.
 * @param count The number of students in the array.
 */
void printStudentsInfo(struct Student students[], int count) {
    printf("Student Information:\n");
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Module: %s\n", students[i].module);
        printf("Age: %d\n", students[i].age);
        printf("Grade: %.2f\n", students[i].grade);
    }
}

/**
 * Frees the memory allocated for the students.
 *
 * @param students Pointer to the dynamically allocated array of Student structs.
 */
void freeStudents(struct Student *students) {
    free(students); // Free the allocated memory
}
