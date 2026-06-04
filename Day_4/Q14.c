//Q14.Write a program to find nth Fibonacci term.

#include <stdio.h>

int fib (int n)
    {
        if (n == 1)
            return 0;
        
        if (n == 2)
            return 1;
        
        else
            return fib(n-1) + fib(n-2);
    }

int main ()
{
    int n;
    printf("Enter the nth term: ");
    scanf("%d", &n);

    printf("%dth Fibonacci term is: %d", n, fib(n));

    return 0;
}