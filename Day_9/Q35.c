// Q35. WAP to print repeated character pattern.
#include <stdio.h>

int main() {
    int i, j, rows;
    char ch;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) 
    {
        ch = 'A' + i - 1;
        for (j = 1; j <= i; j++) 
        {
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;
}
