// Q42. WAP to write function to find maximum.

#include <stdio.h>

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int main() 
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Maximum: %d\n", max(a, b));

    return 0;
}

