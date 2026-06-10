/* Q39. WAP to print number pyramid.

    1
   121
  12321
 1234321
123454321

*/

#include <stdio.h>
int main() 
{
    int i, j, n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= (2 * n - 1); j++) 
        {
            if (j >= n - (i - 1) && j <= n + (i - 1)) 
            {
                if (j <= n) 
                {
                    printf("%d", j - (n - i));
                } 
                else 
                {
                    printf("%d", (n + i) - j);
                }
            } 
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}