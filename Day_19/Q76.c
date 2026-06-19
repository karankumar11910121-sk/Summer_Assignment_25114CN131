// Q76. WAP to find diagonal sum. 

#include <stdio.h>
int main()
{
    int n, i, j, sum = 0;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter elements of matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        sum += matrix[i][i];
    }

    printf("Sum of diagonal elements = %d\n", sum);

    return 0;
}