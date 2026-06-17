// Q67. WAP to intersection of arrays. 

#include <stdio.h>
int main()
{
    int n1, n2, i, j, k, found;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    int arr1[n1];

    printf("Enter %d elements of first array:\n", n1);
    for(i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    int arr2[n2];

    printf("Enter %d elements of second array:\n", n2);
    for(i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    printf("Intersection of arrays: ");

    for(i = 0; i < n1; i++)
    {
        found = 0;
        for(k = 0; k < i; k++)
        {
            if(arr1[i] == arr1[k])
            {
                found = 1;
                break;
            }
        }

        if(found)
            continue;
        for(j = 0; j < n2; j++)
        {
            if(arr1[i] == arr2[j])
            {
                printf("%d ", arr1[i]);
                break;
            }
        }
    }

    return 0;
}