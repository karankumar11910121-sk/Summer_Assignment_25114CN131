// Q119. WAP to create mini employee management system.

#include <stdio.h>
struct Employee
{
    int id;
    char name[50];
    char department[50];
    float salary;
};

int main()
{
    struct Employee emp[100];
    int n = 0;
    int choice, id, i, found;

    do
    {
        printf("\n***** MINI EMPLOYEE MANAGEMENT SYSTEM *****\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp[n].id);

                printf("Enter Employee Name: ");
                scanf(" %[^\n]", emp[n].name);

                printf("Enter Department: ");
                scanf(" %[^\n]", emp[n].department);

                printf("Enter Salary: ");
                scanf("%f", &emp[n].salary);

                n++;
                printf("Employee Added Successfully.\n");
                break;

            case 2:
                if(n == 0)
                {
                    printf("No Employee Records Found.\n");
                }
                else
                {
                    printf("\n----- Employee Records -----\n");

                    for(i = 0; i < n; i++)
                    {
                        printf("\nEmployee %d\n", i + 1);
                        printf("ID         : %d\n", emp[i].id);
                        printf("Name       : %s\n", emp[i].name);
                        printf("Department : %s\n", emp[i].department);
                        printf("Salary     : %.2f\n", emp[i].salary);
                    }
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("No Employee Records Found.\n");
                    break;
                }

                printf("Enter Employee ID to Search: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(emp[i].id == id)
                    {
                        printf("\nEmployee Found\n");
                        printf("ID         : %d\n", emp[i].id);
                        printf("Name       : %s\n", emp[i].name);
                        printf("Department : %s\n", emp[i].department);
                        printf("Salary     : %.2f\n", emp[i].salary);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Employee Not Found.\n");
                }

                break;

            case 4:
                if(n == 0)
                {
                    printf("No Employee Records Found.\n");
                    break;
                }

                printf("Enter Employee ID: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(emp[i].id == id)
                    {
                        printf("Enter New Salary: ");
                        scanf("%f", &emp[i].salary);

                        printf("Salary Updated Successfully.\n");
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Employee Not Found.\n");
                }

                break;

            case 5:
                if(n == 0)
                {
                    printf("No Employee Records Found.\n");
                    break;
                }

                printf("Enter Employee ID to Delete: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(emp[i].id == id)
                    {
                        int j;

                        for(j = i; j < n - 1; j++)
                        {
                            emp[j] = emp[j + 1];
                        }

                        n--;
                        found = 1;
                        printf("Employee Deleted Successfully.\n");
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Employee Not Found.\n");
                }

                break;

            case 6:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice! Please Try Again.\n");
        }

    } while(choice != 6);

    return 0;
}