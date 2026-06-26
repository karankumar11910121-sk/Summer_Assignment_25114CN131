// Q104. WAP to create quiz application.

// WAP to Create Quiz Application

#include <stdio.h>
#include <string.h>
int main()
{
    char name[50];
    int answer, score = 0, totalQuestions = 5;
    float percentage;

    printf("********** QUIZ APPLICATION **********\n\n");

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("\nWelcome %s", name);
    printf("\nEach correct answer = 1 mark\n");
    printf("--------------------------------------\n");

    printf("\nQ1. Which header file is required for printf()?\n");
    printf("1. math.h\n");
    printf("2. string.h\n");
    printf("3. stdio.h\n");
    printf("4. stdlib.h\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 3)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is stdio.h.\n");
    }

    printf("\nQ2. Which symbol is used for single-line comments in C?\n");
    printf("1. //\n");
    printf("2. /* */\n");
    printf("3. ##\n");
    printf("4. <!-- -->\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 1)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is //.\n");
    }

    printf("\nQ3. Which loop executes at least one time?\n");
    printf("1. for\n");
    printf("2. while\n");
    printf("3. do-while\n");
    printf("4. None of these\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 3)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is do-while.\n");
    }

    printf("\nQ4. Which function is used to read input from the user?\n");
    printf("1. printf()\n");
    printf("2. scanf()\n");
    printf("3. puts()\n");
    printf("4. getchar()\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 2)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is scanf().\n");
    }

    printf("\nQ5. Which data type is used to store decimal numbers?\n");
    printf("1. int\n");
    printf("2. char\n");
    printf("3. float\n");
    printf("4. void\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 3)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is float.\n");
    }

    percentage = (score * 100.0) / totalQuestions;

    printf("\n--------------------------------------\n");
    printf("********** RESULT **********\n\n");

    printf("Name       : %s", name);
    printf("Score      : %d/%d\n", score, totalQuestions);
    printf("Percentage : %.2f%%\n", percentage);

    if(score == 5)
    {
        printf("Grade      : Excellent\n");
    }
    else if(score >= 4)
    {
        printf("Grade      : Very Good\n");
    }
    else if(score >= 3)
    {
        printf("Grade      : Good\n");
    }
    else if(score >= 2)
    {
        printf("Grade      : Average\n");
    }
    else
    {
        printf("Grade      : Needs Improvement\n");
    }

    printf("\n-----------*********------------\n");

    return 0;
}