// Q54. WAP to frequency of an element. 

#include <stdio.h>
int main()
{
    int arr[100], i, n, element, count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to find frequency: ");
    scanf("%d", &element);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == element)
        {
            count++;
        }
    }

    printf("Frequency of %d = %d", element, count);

    return 0;
}