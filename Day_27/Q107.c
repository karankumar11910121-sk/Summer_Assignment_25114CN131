// Q107. WAP to create salary management system.

#include <stdio.h>
#define MAX 1000

struct Employee
{
    int empId;
    char name[100];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
};

int main()
{
    struct Employee employee[MAX];
    int choice;
    int count = 0;
    int i, empId, found;

    do
    {
        printf("\n********* SALARY MANAGEMENT SYSTEM **********\n");
        printf("1. Add Employee Salary\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
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

                printf("Enter Basic Salary: ");
                scanf("%f", &employee[count].basicSalary);

                printf("Enter HRA: ");
                scanf("%f", &employee[count].hra);

                printf("Enter DA: ");
                scanf("%f", &employee[count].da);

                employee[count].grossSalary =
                    employee[count].basicSalary +
                    employee[count].hra +
                    employee[count].da;

                count++;

                printf("\nSalary record added successfully.\n");

                break;

            case 2:

                if (count == 0)
                {
                    printf("\nNo employee records available.\n");
                }
                else
                {
                    printf("\n------------ EMPLOYEE SALARY RECORDS ------------\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nEmployee %d\n", i + 1);
                        printf("Employee ID  : %d\n", employee[i].empId);
                        printf("Name         : %s\n", employee[i].name);
                        printf("Basic Salary : %.2f\n", employee[i].basicSalary);
                        printf("HRA          : %.2f\n", employee[i].hra);
                        printf("DA           : %.2f\n", employee[i].da);
                        printf("Gross Salary : %.2f\n", employee[i].grossSalary);
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
                        printf("Employee ID  : %d\n", employee[i].empId);
                        printf("Name         : %s\n", employee[i].name);
                        printf("Basic Salary : %.2f\n", employee[i].basicSalary);
                        printf("HRA          : %.2f\n", employee[i].hra);
                        printf("DA           : %.2f\n", employee[i].da);
                        printf("Gross Salary : %.2f\n", employee[i].grossSalary);

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
                        printf("\nEnter New Employee Name: ");
                        scanf(" %99[^\n]", employee[i].name);

                        printf("Enter New Basic Salary: ");
                        scanf("%f", &employee[i].basicSalary);

                        printf("Enter New HRA: ");
                        scanf("%f", &employee[i].hra);

                        printf("Enter New DA: ");
                        scanf("%f", &employee[i].da);

                        employee[i].grossSalary =
                            employee[i].basicSalary +
                            employee[i].hra +
                            employee[i].da;

                        printf("Salary record updated successfully.\n");

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

                        printf("Employee salary record deleted successfully.\n");

                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Employee not found.\n");

                break;

            case 6:

                printf("\nThank you for using Salary Management System.\n");
                break;

            default:

                printf("\nInvalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}