// Q41. WAP to write function to find sum of two numbers.

#include <stdio.h>

int sum(int a, int b) 
{
    return a + b;
}

int main() 
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Sum: %d\n", sum(a, b));

    return 0;
}
