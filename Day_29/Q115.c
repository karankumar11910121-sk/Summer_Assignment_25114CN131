// Q115. WAP to create menu-driven string operations system.

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 200

void remove_newline(char str[]) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void read_string(char prompt[], char str[]) {
    printf("%s", prompt);
    fgets(str, MAX, stdin);
    remove_newline(str);
}

void reverse_string(char str[], char reversed[]) {
    int i, j = 0;
    int len = strlen(str);

    for (i = len - 1; i >= 0; i--) {
        reversed[j++] = str[i];
    }
    reversed[j] = '\0';
}

void to_uppercase(char str[], char result[]) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        result[i] = toupper((unsigned char)str[i]);
    }
    result[i] = '\0';
}

void to_lowercase(char str[], char result[]) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        result[i] = tolower((unsigned char)str[i]);
    }
    result[i] = '\0';
}

int main() {
    char str1[MAX], str2[MAX], result[MAX * 2];
    int choice;

    do {
        printf("\n----- String Operations Menu -----\n");
        printf("1. Find length of a string\n");
        printf("2. Copy one string to another\n");
        printf("3. Concatenate two strings\n");
        printf("4. Compare two strings\n");
        printf("5. Reverse a string\n");
        printf("6. Convert string to uppercase\n");
        printf("7. Convert string to lowercase\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice) {
            case 1:
                read_string("Enter a string: ", str1);
                printf("Length = %lu\n", strlen(str1));
                break;

            case 2:
                read_string("Enter a string: ", str1);
                strcpy(str2, str1);
                printf("Copied string = %s\n", str2);
                break;

            case 3:
                read_string("Enter first string: ", str1);
                read_string("Enter second string: ", str2);
                strcpy(result, str1);
                strcat(result, str2);
                printf("Concatenated string = %s\n", result);
                break;

            case 4:
                read_string("Enter first string: ", str1);
                read_string("Enter second string: ", str2);

                if (strcmp(str1, str2) == 0) {
                    printf("Both strings are equal.\n");
                } else {
                    printf("Strings are not equal.\n");
                }
                break;

            case 5:
                read_string("Enter a string: ", str1);
                reverse_string(str1, result);
                printf("Reversed string = %s\n", result);
                break;

            case 6:
                read_string("Enter a string: ", str1);
                to_uppercase(str1, result);
                printf("Uppercase string = %s\n", result);
                break;

            case 7:
                read_string("Enter a string: ", str1);
                to_lowercase(str1, result);
                printf("Lowercase string = %s\n", result);
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
