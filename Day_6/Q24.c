//Q24. WAP to find x^n without pow().

#include <stdio.h>
int main ()
{
    int x, n, i, result=1;
    printf("Enter number: ");
    scanf("%d", &x);

    printf("Enter power: ");
    scanf("%d", &n);

    for (i=1; i<=n; i++)
    {
        result = result * x;
    }
    printf("%d^%d = %d", x, n, result);

    return 0;
}
