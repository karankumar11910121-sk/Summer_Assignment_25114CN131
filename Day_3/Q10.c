//Q10.Write a program to Print prime numbers in a range.

#include <stdio.h>
int main ()
{
    int start, end, i, j, prime;

    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    for (i = start; i <= end; i++)
    {
        prime = 1;
        if (i <= 1)
        {
            prime = 0;
        }
        else
        {
            for (j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    prime = 0;
                    break;
                }
            }
        }
        if (prime == 1)
        {
            printf("%d ", i);
            printf("\n");
        }
    }
    return 0;
}