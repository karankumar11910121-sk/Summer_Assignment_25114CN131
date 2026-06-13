// Q50. WAP to find sum and average of array.

#include <stdio.h>
int main()
{
    int arr[5];
    int i, sum = 0;
    float avg;

    for(i = 0; i < 5; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < 5; i++)
    {
        sum += arr[i];
    }

    avg = (float)sum / 5;

    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", avg);

    return 0;
}

