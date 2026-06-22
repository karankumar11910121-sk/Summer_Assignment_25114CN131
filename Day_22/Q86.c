// Q86. WAP to count words in a sentence.

#include <stdio.h>
int main()
{
    char str[200];
    int i, words = 1;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
        {
            words++;
        }
    }

    printf("Total Words = %d", words);

    return 0;
}