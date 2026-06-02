//Q7.Write a program to find product of digits.

#include <stdio.h>
int main ()
{
    int n, prod=1, rem;
    printf("Enter a number: ");
    scanf("%d",&n);

    while (n>0)
    {
        rem = n%10; // to get last digit
        prod = prod * rem; // to multiply last digit to product
        n = n/10; // to remove last digit from number
    }
    printf("Product of digits = %d", prod);
    return 0;
}