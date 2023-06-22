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


void searchStudentsByName(const struct Student* students, int size, const char* searchName) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Student Found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");

            found = 1;
        }
    }

    if (!found) {
        printf("No student found with the name '%s'\n", searchName);
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

    char searchName[20];
    printf("Enter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline character

    searchStudentsByName(students, size, searchName);

    free(students);
    return 0;
}
