// Q80. WAP to find column-wise sum. 

#include <stdio.h>
int main()
{
    int rows, cols, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int a[rows][cols];

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nColumn-wise Sum:\n");

    for(j = 0; j < cols; j++)
    {
        int sum = 0;

        for(i = 0; i < rows; i++)
        {
            sum += a[i][j];
        }

        printf("Sum of Column %d = %d\n", j + 1, sum);
    }

    return 0;
}