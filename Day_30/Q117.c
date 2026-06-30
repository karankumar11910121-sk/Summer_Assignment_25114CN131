// Q117. WAP to create student record system using arrays and strings.

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
struct Student {
    int rollNo;
    char name[NAME_LENGTH];
    float marks;
};

int findStudent(struct Student students[], int count, int rollNo) {
    int i;

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            return i;
        }
    }

    return -1;
}

void readName(char name[]) {
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n***** Student Record System *****\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student by roll number\n");
        printf("4. Update student marks\n");
        printf("5. Delete student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            int rollNo;

            if (count == MAX_STUDENTS) {
                printf("Record list is full.\n");
                continue;
            }

            printf("Enter roll number: ");
            scanf("%d", &rollNo);
            getchar();

            if (findStudent(students, count, rollNo) != -1) {
                printf("A student with this roll number already exists.\n");
                continue;
            }

            students[count].rollNo = rollNo;

            printf("Enter student name: ");
            readName(students[count].name);

            printf("Enter marks: ");
            scanf("%f", &students[count].marks);
            getchar();

            count++;
            printf("Student record added successfully.\n");
        } else if (choice == 2) {
            int i;

            if (count == 0) {
                printf("No student records found.\n");
            } else {
                printf("\n%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
                printf("-----------------------------------------------\n");

                for (i = 0; i < count; i++) {
                    printf("%-10d %-25s %-10.2f\n",
                           students[i].rollNo,
                           students[i].name,
                           students[i].marks);
                }
            }
        } else if (choice == 3) {
            int rollNo;
            int index;

            printf("Enter roll number to search: ");
            scanf("%d", &rollNo);
            getchar();

            index = findStudent(students, count, rollNo);

            if (index == -1) {
                printf("Student record not found.\n");
            } else {
                printf("\nStudent Found\n");
                printf("Roll Number: %d\n", students[index].rollNo);
                printf("Name       : %s\n", students[index].name);
                printf("Marks      : %.2f\n", students[index].marks);
            }
        } else if (choice == 4) {
            int rollNo;
            int index;

            printf("Enter roll number to update marks: ");
            scanf("%d", &rollNo);
            getchar();

            index = findStudent(students, count, rollNo);

            if (index == -1) {
                printf("Student record not found.\n");
            } else {
                printf("Enter new marks: ");
                scanf("%f", &students[index].marks);
                getchar();

                printf("Marks updated successfully.\n");
            }
        } else if (choice == 5) {
            int rollNo;
            int index;
            int i;

            printf("Enter roll number to delete: ");
            scanf("%d", &rollNo);
            getchar();

            index = findStudent(students, count, rollNo);

            if (index == -1) {
                printf("Student record not found.\n");
            } else {
                for (i = index; i < count - 1; i++) {
                    students[i] = students[i + 1];
                }

                count--;
                printf("Student record deleted successfully.\n");
            }
        } else if (choice == 6) {
            printf("Exiting program.\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}