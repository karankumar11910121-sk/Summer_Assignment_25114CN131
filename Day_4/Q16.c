//Q16.Write a program to print Armstrong numbers in a range.

#include <stdio.h>
int main()
{
    int n, start, end, temp, sum, r;
    
    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    printf("Armstrong numbers b/w %d and %d are:\n",start, end);

    for (n = start; n <= end; n++)
    {
        temp = n;
        sum = 0;

        while (temp > 0)
        {
            r = temp % 10;
            sum = sum + (r * r * r);
            temp = temp / 10;
        }
        if (n == sum) 
        {
            printf("%d ", n);
        }
    }
    
    return 0;
}