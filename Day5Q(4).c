#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* inputString, struct Student* students, int size) {
    char* token = strtok(inputString, " ");
    int count = 0;

    while (token != NULL && count < size) {
        students[count].rollno = atoi(token);
        token = strtok(NULL, " ");
        strncpy(students[count].name, token, sizeof(students[count].name));
        token = strtok(NULL, " ");
        students[count].marks = atof(token);

        token = strtok(NULL, " ");
        count++;
    }
}

void initializeStudents(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

void displayStudents(const struct Student* students, int size) {
    printf("Student Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

void sortStudents(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap the positions of students[j] and students[j + 1]
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); // Clear the newline character from the input buffer

    struct Student* students = malloc(size * sizeof(struct Student));

    // Initialize all members of the array of structures
    initializeStudents(students, size);

    printf("Enter the student details:\n");
    for (int i = 0; i < size; i++) {
        char inputString[100];
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = '\0'; // Remove newline character

        parseString(inputString, &students[i], size);
    }

    // Sort the array of structures based on marks in descending order
    sortStudents(students, size);

    // Display the sorted array of structures
    displayStudents(students, size);

    free(students);
    return 0;
}
