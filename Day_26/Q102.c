// Q102. WAP to create voting eligibility system.

#include <stdio.h>
int main()
{
    int age;

    printf("\n*** Voting Eligibility System ***\n\n");

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 0)
    {
        printf("Invalid age entered.\n");
    }
    else if (age >= 18)
    {
        printf("You are eligible to vote.\n");
    }
    else
    {
        printf("You are not eligible to vote.\n");
        printf("You can vote after %d year(s).\n", 18 - age);
    }

    return 0;
}