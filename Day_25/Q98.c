// Q98. WAP to find common characters in strings.

#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];
    int i, j, k, found;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    printf("Common characters: ");

    found = 0;

    for(i = 0; str1[i] != '\0'; i++)
    {
        int alreadyPrinted = 0;
        for(k = 0; k < i; k++)
        {
            if(str1[i] == str1[k])
            {
                alreadyPrinted = 1;
                break;
            }
        }

        if(alreadyPrinted)
        {
            continue;
        }

        for(j = 0; str2[j] != '\0'; j++)
        {
            if(str1[i] == str2[j])
            {
                printf("%c ", str1[i]);
                found = 1;
                break;
            }
        }
    }

    if(found == 0)
    {
        printf("No common characters");
    }

    return 0;
}