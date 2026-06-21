// Q81. WAP to find string length without strlen().

#include <stdio.h>
int main()
{
    char str[100];
    int i = 0, length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0' && str[i] != '\n')
    {
        length++;
        i++;
    }

    printf("Length of string = %d\n", length);

    return 0;
}