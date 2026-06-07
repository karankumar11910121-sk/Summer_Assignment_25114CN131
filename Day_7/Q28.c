//Q28. WAP to Recursive reverse number.

#include <stdio.h>

int ReverseNumber(int n, int rev)
{
    if (n == 0)
        return rev;
    else
    {
        rev = rev*10 + n%10;
        return ReverseNumber(n/10, rev);
    }
}

int main ()
{
    int n, rev=0;
    printf("Enter number: ");
    scanf("%d", &n);

    printf("Reverse of %d is %d", n, ReverseNumber(n, rev) );
    return 0;
}