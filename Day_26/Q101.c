// Q101. WAP to create number guessing game.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int secretNumber, guess, attempts = 0;

    srand(time(NULL));
    secretNumber = rand() % 100 + 1;

    printf("\n*** NUMBER GUESSING GAME ***\n\n");
    printf("Guess a number between 1 and 100.\n");

    do
    {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess > secretNumber)
        {
            printf("Too High! Try Again.\n");
        }
        else if (guess < secretNumber)
        {
            printf("Too Low! Try Again.\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the correct number.\n");
            printf("Secret Number = %d\n", secretNumber);
            printf("Total Attempts = %d\n", attempts);
        }

    } while (guess != secretNumber);

    return 0;
}