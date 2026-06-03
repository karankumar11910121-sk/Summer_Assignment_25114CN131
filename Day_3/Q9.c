//Q9.Write a program to check whether a number is prime.

#include <stdio.h>
int main ()
{
    int n, i, prime =1;
    scanf("%d", &n);

    if (n<= 1)
    {
        prime = 0;
    }
    else
    {
        for (i = 2 ; i <= n/2 ; i++)
        {
            if (n % i == 0)
            {
                prime = 0 ;
                break;
            }
        }
    }
    if (prime == 1)
    {
        printf("%d is a prime number. \n",n);
    }
    else 
    {
        printf ("%d is not a prime number. \n", n);
    }
    return 0;
}