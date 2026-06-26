// Q103. WAP to create ATM simulation.

#include <stdio.h>
int main()
{
    int pin, enteredPin, choice;
    float balance, amount;

    printf("***** ATM Account Setup *****\n");

    printf("Set your 4-digit PIN: ");
    scanf("%d", &pin);

    printf("Enter Initial Balance: ");
    scanf("%f", &balance);

    printf("\n***** ATM Login ****\n");

    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin)
    {
        printf("Invalid PIN! Access Denied.\n");
        return 0;
    }

    do
    {
        printf("\n***** ATM Menu *****\n\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Current Balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                if (amount > 0)
                {
                    balance += amount;
                    printf("Amount Deposited Successfully.\n");
                    printf("Updated Balance: %.2f\n", balance);
                }
                else
                {
                    printf("Invalid amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if (amount <= 0)
                {
                    printf("Invalid amount!\n");
                }
                else if (amount > balance)
                {
                    printf("Insufficient Balance!\n");
                }
                else
                {
                    balance -= amount;
                    printf("Please collect your cash.\n");
                    printf("Remaining Balance: %.2f\n", balance);
                }
                break;

            case 4:
                printf("Thank you for using our ATM.\n");
                break;

            default:
                printf("Invalid Choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}