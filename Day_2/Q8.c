//Q8.Write a program to check whether a number is palindrome.

#include <stdio.h>
int main ()
{
    int n, rev=0, rem, temp;
    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n; // to store original number

    while (n>0)
    {
        rem = n%10; // to get last digit
        rev = rev*10 + rem; // to add last digit 
        n = n/10; // to remove last digit from number
    }

    if (temp == rev)
    {
        printf("%d is a palindrome number", temp);
    }
    else
    {
        printf("%d is not a palindrome number", temp);
    }
    return 0;
}