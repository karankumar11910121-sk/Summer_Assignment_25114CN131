// Q75. WAP to Transpose Matrix.

#include <stdio.h>
int main()
{
    int rows, cols, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose Matrix:\n");
    for(i = 0; i < cols; i++)
    {
        for(j = 0; j < rows; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}