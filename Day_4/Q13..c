//Q13.Write a program to generate Fibonacci Series.
// 0 1 1 2 3 5 8 13 21 34 ...

#include <stdio.h>

int main ()
{
    int n, a = 0, b = 1, c = 0, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    
    return 0;
}
