// Q62. WAP to find maximum frequency element.

#include <stdio.h>
int main() 
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];   

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int maxFreq = 0, maxElement;

    for (int i = 0; i < n; i++) 
    {
        int count = 0;

        for (int j = 0; j < n; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                count++;
            }
        }

        if (count > maxFreq) 
        {
            maxFreq = count;
            maxElement = arr[i];
        }
    }

    printf("Element with maximum frequency = %d\n", maxElement);
    printf("Frequency of element = %d\n", maxFreq);

    return 0;
}