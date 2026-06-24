// Q95. WAP to find longest word. 

#include <stdio.h>
#include <string.h>
int main()
{
    char str[200], longest[50];
    int i = 0, j = 0, maxLen = 0, len = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while (1)
    {
        if (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
        {
            len++;
        }
        else
        {
            if (len > maxLen)
            {
                maxLen = len;

                for (j = 0; j < len; j++)
                {
                    longest[j] = str[i - len + j];
                }

                longest[len] = '\0';
            }

            len = 0;

            if (str[i] == '\0' || str[i] == '\n')
            {
                break;
            }
        }

        i++;
    }

    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", maxLen);

    return 0;
}