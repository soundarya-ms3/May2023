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

    // Print the initialized array of structures
    printf("\nStudent Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);
    return 0;
}
