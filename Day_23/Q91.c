// Q91. WAP to check anagram strings.

#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];
    int freq1[256] = {0}, freq2[256] = {0}, i, isAnagram = 1;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if(strlen(str1) != strlen(str2))
    {
        isAnagram = 0;
    }
    else
    {
        for(i = 0; str1[i] != '\0'; i++)
        {
            freq1[(unsigned char)str1[i]]++;
            freq2[(unsigned char)str2[i]]++;
        }

        for(i = 0; i < 256; i++)
        {
            if(freq1[i] != freq2[i])
            {
                isAnagram = 0;
                break;
            }
        }
    }

    if(isAnagram)
    {
        printf("Strings are Anagrams.");
    }
    else
    {
        printf("Strings are Not Anagrams.");
    }
    
    return 0;
}