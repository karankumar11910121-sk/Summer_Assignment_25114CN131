// Q79. WAP to find row-wise sum. 

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
            printf("Element [%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nRow-wise Sum:\n");

    for(i = 0; i < rows; i++)
    {
        int sum = 0;

        for(j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }

        printf("Sum of Row %d = %d\n", i + 1, sum);
    }

    return 0;
}