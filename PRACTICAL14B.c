#include <stdio.h>

struct Student {
    char name[50];
    int mathMarks;
    int scienceMarks;
    int englishMarks;
};

void writeStudentDataToFile(struct Student students[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < size; ++i) {
        fprintf(file, "%s %d %d %d\n", students[i].name, students[i].mathMarks, students[i].scienceMarks, students[i].englishMarks);
    }

    fclose(file);
}

void readStudentDataFromFile(struct Student students[], int size, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    for (int i = 0; i < size; ++i) {
        fscanf(file, "%s %d %d %d", students[i].name, &students[i].mathMarks, &students[i].scienceMarks, &students[i].englishMarks);
    }

    fclose(file);
}

int main() {
    const int size = 3; 
    struct Student students[size];

    for (int i = 0; i < size; ++i) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Math Marks: ");
        scanf("%d", &students[i].mathMarks);
        printf("Science Marks: ");
        scanf("%d", &students[i].scienceMarks);
        printf("English Marks: ");
        scanf("%d", &students[i].englishMarks);
    }

    writeStudentDataToFile(students, size, "StudentData.txt");
    printf("Student data written to file successfully.\n");

    for (int i = 0; i < size; ++i) {
        students[i].name[0] = '\0';
        students[i].mathMarks = 0;
        students[i].scienceMarks = 0;
        students[i].englishMarks = 0;
    }

    readStudentDataFromFile(students, size, "StudentData.txt");

    printf("\nTotal Marks for Each Student (Read from File):\n");
    for (int i = 0; i < size; ++i) {
        int totalMarks = students[i].mathMarks + students[i].scienceMarks + students[i].englishMarks;
        printf("%s: %d\n", students[i].name, totalMarks);
    }

    return 0;
}
