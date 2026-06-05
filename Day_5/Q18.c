//Q18. WAP to check a strong number.

#include<stdio.h>
int main ()
{
    int n, r, fact, sum, i, num;
    printf("Enter no.:");
    scanf ("%d", &n) ;

    num = n;
    sum = 0;

    while (n>0)
    {
        r = n%10;
        fact = 1;

        for (i=1; i<=r; i++)
        {
            fact *= i;
        }
        sum += fact;
        n /= 10;
    }

    if (sum == num)
    {
        printf("%d is a strong number.", num);
    }
    else
    {
        printf("%d is not a strong number.", num);
    }

    return 0;
}