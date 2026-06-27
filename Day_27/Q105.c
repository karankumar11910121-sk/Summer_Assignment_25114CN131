// Q105. WAP to create student record management system.

#include <stdio.h>
#define MAX 1000
struct Student 
{
    int roll;
    char name[100];
    int age;
    float marks;
};

int main() 
{
    struct Student student[MAX];
    int choice;
    int count = 0;
    int i, roll, found;

    do {
        printf("\n********* STUDENT RECORD MANAGEMENT **********\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input type! Exiting safely.\n");
            break;
        }

        switch(choice) 
        {
            case 1:
                if (count == MAX) {
                    printf("\nRecord storage is full!\n");
                    break;
                }
                
                printf("\nEnter Roll Number: ");
                scanf("%d", &roll);
                
                found = 0;
                for (i = 0; i < count; i++) {
                    if (student[i].roll == roll) {
                        printf("Error: A student with Roll Number %d already exists.\n", roll);
                        found = 1;
                        break;
                    }
                }
                if (found) break;

                student[count].roll = roll;
                printf("Enter Name (Max 99 chars): ");
                scanf(" %99[^\n]", student[count].name); 
                
                printf("Enter Age: ");
                scanf("%d", &student[count].age);
                printf("Enter Marks: ");
                scanf("%f", &student[count].marks);
                
                count++;
                printf("\nStudent record added successfully.\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo records available.\n");
                } else {
                    printf("\n------------- STUDENT RECORDS -------------\n");
                    for (i = 0; i < count; i++) {
                        printf("\nStudent %d\n", i + 1);
                        printf("Roll Number : %d\n", student[i].roll);
                        printf("Name        : %s\n", student[i].name);
                        printf("Age         : %d\n", student[i].age);
                        printf("Marks       : %.2f\n", student[i].marks);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo records available.\n");
                    break;
                }
                printf("Enter Roll Number to Search: ");
                scanf("%d", &roll);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (student[i].roll == roll) {
                        printf("\nStudent Found\n");
                        printf("Roll Number : %d\n", student[i].roll);
                        printf("Name        : %s\n", student[i].name);
                        printf("Age         : %d\n", student[i].age);
                        printf("Marks       : %.2f\n", student[i].marks);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Student not found.\n");
                break;

            case 4:
                if (count == 0) {
                    printf("\nNo records available.\n");
                    break;
                }
                printf("Enter Roll Number to Update: ");
                scanf("%d", &roll);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (student[i].roll == roll) {
                        printf("\nEnter New Name (Max 99 chars): ");
                        scanf(" %99[^\n]", student[i].name);
                        printf("Enter New Age: ");
                        scanf("%d", &student[i].age);
                        printf("Enter New Marks: ");
                        scanf("%f", &student[i].marks);
                        printf("Record updated successfully.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Student not found.\n");
                break;

            case 5:
                if (count == 0) {
                    printf("\nNo records available.\n");
                    break;
                }
                printf("Enter Roll Number to Delete: ");
                scanf("%d", &roll);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (student[i].roll == roll) 
                    {
                        for (int j = i; j < count - 1; j++) {
                            student[j] = student[j + 1];
                        }
                        count--;
                        printf("Record deleted successfully.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Student not found.\n");
                break;

            case 6:
                printf("\nThank you for using Student Record Management System.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 6);

    return 0;
}