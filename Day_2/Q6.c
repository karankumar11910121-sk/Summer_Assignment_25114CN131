//Q6.Write a program to reverse a number

#include <stdio.h>
int main ()
{
    int n, rev=0, rem;
    printf("Enter a number:");
    scanf("%d", &n);
     
    while (n>0)
    {
        rem = n%10; // to get last digit
        rev = rev*10 + rem; //to add last digit to reverse number
        n = n/10;  // to remove last digit from number
    }
    printf("Reversed number = %d", rev);
    return 0;

}