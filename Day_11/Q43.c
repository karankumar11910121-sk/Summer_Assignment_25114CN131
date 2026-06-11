// Q43. WAP to write function to check prime.

#include <stdio.h>

int Prime (int n) 
{
    if (n <= 1) 
    return 0;

    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) 
        return 0;
    }
    return 1;
}

int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if (Prime(n))
        printf("%d is prime.\n", n);
    else
        printf("%d is not prime.\n", n);

    return 0;
}
