// Q61. WAP to find missing number in array.

#include <stdio.h>

int main() {
    int n;

    printf("Enter the highest number (n): ");
    scanf("%d", &n);

    int arr[n];   
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int expectedSum = n * (n + 1) / 2; 
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    int missingNumber = expectedSum - actualSum;

    printf("Missing number is: %d\n", missingNumber);

    return 0;
}