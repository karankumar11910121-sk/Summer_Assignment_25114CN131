// Q92. WAP to find maximum occurring character.

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], maxChar;
    int freq[256] = {0}, i, max = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != '\n')   
        {
            freq[(unsigned char)str[i]]++;
        }
    }

    for(i = 0; i < 256; i++)
    {
        if(freq[i] > max)
        {
            max = freq[i];
            maxChar = i;
        }
    }

    if(max == 1)
    {
        printf("No character repeats. All characters occur only once.\n");
    }
    else
    {
        printf("Maximum occurring character = '%c'\n", maxChar);
        printf("Frequency = %d\n", max);
    }

    return 0;
}