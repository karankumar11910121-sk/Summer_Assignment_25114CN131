// Q46. WAP to write function for armstrong.

#include <stdio.h>
#include <math.h>

int Armstrong(int n)
{
    int original = n, remainder, result = 0;

    while (original != 0)
    {
        remainder = original % 10;
        result += pow(remainder, 3);
        original /= 10;
    }

    if (result == n)
        return 1;
    else
        return 0;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (Armstrong(n))
        printf("%d is an Armstrong Number.", n);
    else
        printf("%d is not an Armstrong Number.", n);

    return 0;
}
