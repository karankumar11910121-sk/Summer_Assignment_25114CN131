// Q23. WAP to count set bits in a number.

// Set bits -> It is a bit whose value is 1 in binary representation of number.

#include <stdio.h>
int main()
{
    int n, count=0, temp;
    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;
    while (n > 0)
    {
        if(n%2 == 1)
        {
            count++;
        }
        n = n / 2;
    }
    printf("Number of set bits of %d decimal is: %d", temp, count);

    return 0;
}
