/* Q40. WAP to print character pyramid. 

    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

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
                    printf("%c", 'A' - 1 + j - (n - i));
                } 
                else 
                {
                    printf("%c", 'A' - 1 + (n + i) - j);
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
