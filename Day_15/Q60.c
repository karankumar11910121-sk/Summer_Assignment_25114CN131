// Q60. WAP to move zeroes to end.

#include <stdio.h>
int main() 
{
    int n, i, j = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], result[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) 
    {
        if(arr[i] != 0) 
        {
            result[j] = arr[i];
            j++;
        }
    }

    while(j < n)
    {
        result[j] = 0;
        j++;
    }

    printf("Array after moving zeroes to end:\n");
    for(i = 0; i < n; i++) 
    {
        printf("%d ", result[i]);
    }

    return 0;
}