// Q78. WAP to check symmetric matrix. 

#include <stdio.h>
int main()
{
    int n, i, j;
    int isSymmetric = 1;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);
    
    int a[n][n];

    printf("Enter matrix elements:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }

        if(isSymmetric == 0)
        {
            break;
        }
    }

    if(isSymmetric == 1)
    {
        printf("Matrix is Symmetric.\n");
    }
    else
    {
        printf("Matrix is Not Symmetric.\n");
    }

    return 0;
}