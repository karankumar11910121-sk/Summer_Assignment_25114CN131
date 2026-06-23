// Q90. WAP to find first repeating character.

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], firstRepeating = '\0';
    int i, j;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        for(j = i + 1; str[j] != '\0'; j++)
        {
            if(str[i] == str[j] && str[i] != '\n')
            {
                firstRepeating = str[i];
                break;
            }
        }

        if(firstRepeating != '\0')
        {
            break;
        }
    }

    if(firstRepeating != '\0')
    {
        printf("First repeating character = %c\n", firstRepeating);
    }
    else
    {
        printf("No repeating character found.\n");
    }

    return 0;
}