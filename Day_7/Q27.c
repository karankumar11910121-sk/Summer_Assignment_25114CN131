//Q27.WAP to Recursive sum of digits. 

#include <stdio.h>

int SumOfDigits(int n)
{
    if  (n == 0)
        return 0;
    else
        return (n%10) + SumOfDigits(n/10);
}

int main ()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    printf("Sum of digits of %d is %d", n, SumOfDigits(n) );
    return 0;
}