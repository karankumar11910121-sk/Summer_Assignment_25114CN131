// Q100. WAP to sort words by length. 

#include <stdio.h>
#include <string.h>
int main()
{
    char str[200];
    char words[100][50];
    char temp[50];
    int i = 0, j, count = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    char *token = strtok(str, " ");
    while(token != NULL)
    {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " ");
    }

    for(i = 0; i < count - 1; i++)
    {
        for(j = i + 1; j < count; j++)
        {
            if(strlen(words[i]) > strlen(words[j]))
            {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for(i = 0; i < count; i++)
    {
        printf("%s ", words[i]);
    }

    return 0;
}