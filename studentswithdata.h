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
    StudentRec students[MAX_STUDENTS] = {
        {"Jane", "Smith", 100},
        {"Dough", "Jennings", 33},
        {"Sandy", "Adam", 89.5},
        {"Rick", "Mayer", 72},
        {"Eva", "Yoo", 85}
    };
    
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
