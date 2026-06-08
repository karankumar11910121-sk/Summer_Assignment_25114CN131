//Q31. WAP to print character triangle.

#include <stdio.h>
int main() 
{
    int i, j, rows;
    char ch;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        ch = 'A';
        for (j = 1; j <= i; j++) {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }
    return 0;
}
