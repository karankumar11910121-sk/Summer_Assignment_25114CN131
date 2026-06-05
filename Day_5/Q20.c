//Q20. WAP to find largest prime factor.

#include<stdio.h>   
int main ()
{
    int n, i, larg;
    printf("Enter no.:");
    scanf ("%d", &n) ;

    larg = 1;
    for(i=2; i<=n; i++)
    {
        while (n%i==0)
        {
            larg = i;
            n /= i;
        }
    }
    printf("Largest prime factor = %d", larg);
    return 0;
}