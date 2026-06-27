// Q106. WAP to create employee management system.

#include <stdio.h>
#define MAX 1000
struct Employee
{
    int empId;
    char name[100];
    int age;
    float salary;
};

int main()
{
    struct Employee employee[MAX];
    int choice;
    int count = 0;
    int i, empId, found;

    do
    {
        printf("\n********* EMPLOYEE MANAGEMENT SYSTEM **********\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input type! Exiting safely.\n");
            break;
        }

        switch (choice)
        {
            case 1:
                if (count == MAX)
                {
                    printf("\nEmployee storage is full!\n");
                    break;
                }

                printf("\nEnter Employee ID: ");
                if (scanf("%d", &empId) != 1)
                {
                    printf("Invalid Employee ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (i = 0; i < count; i++)
                {
                    if (employee[i].empId == empId)
                    {
                        printf("Error: Employee ID %d already exists.\n", empId);
                        found = 1;
                        break;
                    }
                }

                if (found)
                    break;

                employee[count].empId = empId;

                printf("Enter Employee Name (Max 99 chars): ");
                scanf(" %99[^\n]", employee[count].name);

                printf("Enter Age: ");
                scanf("%d", &employee[count].age);

                printf("Enter Salary: ");
                scanf("%f", &employee[count].salary);

                count++;

                printf("\nEmployee added successfully.\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo employee records available.\n");
                }
                else
                {
                    printf("\n------------ EMPLOYEE RECORDS ------------\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nEmployee %d\n", i + 1);
                        printf("Employee ID : %d\n", employee[i].empId);
                        printf("Name        : %s\n", employee[i].name);
                        printf("Age         : %d\n", employee[i].age);
                        printf("Salary      : %.2f\n", employee[i].salary);
                    }
                }
                break;

            case 3:
                if (count == 0)
                {
                    printf("\nNo employee records available.\n");
                    break;
                }

                printf("Enter Employee ID to Search: ");
                if (scanf("%d", &empId) != 1)
                {
                    printf("Invalid Employee ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (employee[i].empId == empId)
                    {
                        printf("\nEmployee Found\n");
                        printf("Employee ID : %d\n", employee[i].empId);
                        printf("Name        : %s\n", employee[i].name);
                        printf("Age         : %d\n", employee[i].age);
                        printf("Salary      : %.2f\n", employee[i].salary);

                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Employee not found.\n");

                break;

            case 4:
                if (count == 0)
                {
                    printf("\nNo employee records available.\n");
                    break;
                }

                printf("Enter Employee ID to Update: ");
                if (scanf("%d", &empId) != 1)
                {
                    printf("Invalid Employee ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (employee[i].empId == empId)
                    {
                        printf("\nEnter New Name (Max 99 chars): ");
                        scanf(" %99[^\n]", employee[i].name);

                        printf("Enter New Age: ");
                        scanf("%d", &employee[i].age);

                        printf("Enter New Salary: ");
                        scanf("%f", &employee[i].salary);

                        printf("Employee record updated successfully.\n");

                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Employee not found.\n");

                break;

            case 5:
                if (count == 0)
                {
                    printf("\nNo employee records available.\n");
                    break;
                }

                printf("Enter Employee ID to Delete: ");
                if (scanf("%d", &empId) != 1)
                {
                    printf("Invalid Employee ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (employee[i].empId == empId)
                    {
                        for (int j = i; j < count - 1; j++)
                        {
                            employee[j] = employee[j + 1];
                        }

                        count--;

                        printf("Employee record deleted successfully.\n");

                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Employee not found.\n");

                break;

            case 6:
                printf("\nThank you for using Employee Management System.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}