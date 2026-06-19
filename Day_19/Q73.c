// Q73. WAP to Add matrices. 

#include <stdio.h>
int main()
{
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int a[rows][cols], b[rows][cols], sum[rows][cols];

    printf("\nEnter elements of First Matrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of Second Matrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("b[%d][%d] = ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nSum of Matrices:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}