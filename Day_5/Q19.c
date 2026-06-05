//Q19.WAP to print factors of a number. 

#include<stdio.h>
int main ()
{
    int i, n;
    printf("Enter no.:");
    scanf ("%d", &n) ;

    printf("Factors of %d are: ", n);

    for (i=1; i<=n; i++)
    {
        if (n%i==0)
         {
             printf("%d ", i);
         }
    }

    return 0;
}