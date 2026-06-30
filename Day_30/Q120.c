// Q120. WAP to develop complete mini project using arrays, strings and functions.

#include <stdio.h>
#include <string.h>

#define MAX 100
struct Student
{
    int roll;
    char name[50];
    float marks;
};

struct Student s[MAX];
int n = 0;

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main()
{
    int choice;

    do
    {
        printf("\n********** STUDENT RECORD MANAGEMENT SYSTEM **********\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

void addStudent()
{
    if(n == MAX)
    {
        printf("Record is Full!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[n].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[n].name);

    printf("Enter Marks: ");
    scanf("%f", &s[n].marks);

    n++;

    printf("Student Added Successfully!\n");
}

void displayStudents()
{
    int i;

    if(n == 0)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n--------------- Student Records ---------------\n");

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number : %d\n", s[i].roll);
        printf("Name        : %s\n", s[i].name);
        printf("Marks       : %.2f\n", s[i].marks);
    }
}

void searchStudent()
{
    int roll, i, found = 0;

    if(n == 0)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++)
    {
        if(s[i].roll == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", s[i].roll);
            printf("Name        : %s\n", s[i].name);
            printf("Marks       : %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Student Not Found!\n");
}

void updateStudent()
{
    int roll, i, found = 0;

    if(n == 0)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++)
    {
        if(s[i].roll == roll)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("Record Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Student Not Found!\n");
}

void deleteStudent()
{
    int roll, i, j, found = 0;

    if(n == 0)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++)
    {
        if(s[i].roll == roll)
        {
            for(j = i; j < n - 1; j++)
            {
                s[j] = s[j + 1];
            }

            n--;
            found = 1;
            printf("Record Deleted Successfully!\n");
            break;
        }
    }

    if(found == 0)
        printf("Student Not Found!\n");
}