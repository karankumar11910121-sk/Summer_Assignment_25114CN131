//Q5. Write a program to Find sum of digits of a number

#include <stdio.h>
int main()
{
    int n, sum=0, rem;
    printf("Enter a number:");
    scanf("%d",&n);
    
    while (n>0)
    {
        rem = n%10; //to get last digit
        sum = sum + rem; //to add last digit to sum
        n = n/10;  //to remove last digit from number
    }

    printf("Sum of digits is %d",sum);
    return 0;
}
