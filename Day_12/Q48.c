// Q48. WAP to write function for perfect number.

#include <stdio.h>

int Perfect(int n)
{
    int i, sum = 0;

    for(i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            sum += i;
        }
    }

    if(sum == n)
        return 1;
    else
        return 0;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(Perfect(n))
        printf("%d is a Perfect Number.", n);
    else
        printf("%d is not a Perfect Number.", n);

    return 0;
}






