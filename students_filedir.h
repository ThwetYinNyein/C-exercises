#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 5

// Struct to store student information
typedef struct {
    char firstName[50];
    char lastName[50];
    float grade;
} StudentRec;

int main() {
    StudentRec students[MAX_STUDENTS];
    FILE *file = fopen("sample1.txt", "r"); // Open the file for reading
    
    if (file == NULL) {
        printf("Error opening file!\n");
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
