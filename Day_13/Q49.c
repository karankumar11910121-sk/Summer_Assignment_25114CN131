// Q49. WAP to input and display array. 

#include <stdio.h>
int main()
{
    int arr[5];
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}