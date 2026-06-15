// Q58. WAP to rotate array left.

#include <stdio.h>
int main()
{
    int n, i, first;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    first = arr[0];

    for(i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = first;

    printf("Array after left rotation: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}