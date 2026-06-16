// Q64. WAP to remove duplicates from array.

#include <stdio.h>
int main() 
{
    int n, i, j, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) 
    {
        for(j = i + 1; j < n; j++) 
        {
            if(arr[i] == arr[j]) 
            {
                for(k = j; k < n - 1; k++) 
                {
                    arr[k] = arr[k + 1];
                }
                n--;    
                j--;    
            }
        }
    }

    printf("Array after removing duplicates: ");
    for(i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}