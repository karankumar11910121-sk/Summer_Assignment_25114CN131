//Q11.Write a program to find GCD of two numbers. 

#include <stdio.h>
int main ()
{
    int  a, b, gcd = 1;
    printf ("Enter two numbers: ");
    scanf ("%d %d", &a, &b);

    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    printf("GCD of %d and %d is: %d\n", a, b, gcd);
    return 0;
}