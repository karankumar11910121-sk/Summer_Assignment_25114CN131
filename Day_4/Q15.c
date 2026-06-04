//Q15.Write a program to check Armstrong number. 

#include <stdio.h>
int main ()
{
    int n, temp, sum = 0, r;

    printf("Enter any number: ");
    scanf("%d", &n);

    temp = n;

    while(n > 0)
    {
        r = n % 10;
        sum = sum + (r * r * r);
        n = n / 10;
    }

    if (temp == sum)
        printf("%d is an Armstrong number.", temp);
    else
        printf("%d is not an Armstrong number.", temp);

    return 0;
}
