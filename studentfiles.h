#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 5

// Struct to store student information
typedef struct {
    char firstName[50];
    char lastName[50];
    float grade;
} StudentRec;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1; // Exit if the filename is not provided
    }

    StudentRec students[MAX_STUDENTS];
    FILE *file = fopen(argv[1], "r"); // Open the file specified in command-line argument

    if (file == NULL) {
        printf("Error opening file '%s'!\n", argv[1]);
        return 1; // Exit if file can't be opened
    }

    // Read student data from file
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (fscanf(file, "%49s %49s %f", students[i].firstName, students[i].lastName, &students[i].grade) != 3) {
            printf("Error reading data for student %d\n", i + 1);
            fclose(file);
            return 1; // Exit if there is an issue with the file format
        }
    }

    fclose(file); // Close the file

    float totalGrade = 0.0;

    // Calculate total grades
    for (int i = 0; i < MAX_STUDENTS; i++) {
        totalGrade += students[i].grade;
    }

    // Calculate the average grade
    float averageGrade = totalGrade / MAX_STUDENTS;

    // Print the average grade
    printf("Average grade: %.1f\n", averageGrade);

    // Print the last names of the students
    printf("Last names of students:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%s\n", students[i].lastName);
    }

    return 0;
}
