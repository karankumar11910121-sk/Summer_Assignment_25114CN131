// Q110. WAP to create bank account system.

#include <stdio.h>
#include <string.h>

#define MAX 100
struct Account {
    int accountNumber;
    char holderName[50];
    float balance;
};

struct Account accounts[MAX];
int count = 0;

int findAccountIndex(int accNo) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNo) {
            return i;
        }
    }
    return -1;
}

void addAccount() {
    if (count >= MAX) {
        printf("\nAccount limit reached!\n");
        return;
    }

    int accNo;
    float balance;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    if (findAccountIndex(accNo) != -1) {
        printf("Account number already exists!\n");
        return;
    }

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", accounts[count].holderName);

    printf("Enter Initial Balance: ");
    scanf("%f", &balance);

    if (balance < 0) {
        printf("Initial balance cannot be negative!\n");
        return;
    }

    accounts[count].accountNumber = accNo;
    accounts[count].balance = balance;
    count++;

    printf("Account added successfully!\n");
}

void displayAllAccounts() {
    if (count == 0) {
        printf("\nNo accounts available.\n");
        return;
    }

    printf("\n--- All Accounts Of The Bank ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nAccount Number: %d", accounts[i].accountNumber);
        printf("\nHolder Name: %s", accounts[i].holderName);
        printf("\nBalance: %.2f\n", accounts[i].balance);
    }
}

void searchAccount() {
    int accNo;
    printf("\nEnter Account Number to Search: ");
    scanf("%d", &accNo);

    int index = findAccountIndex(accNo);

    if (index == -1) {
        printf("Account not found!\n");
    } else {
        printf("\nAccount Found!");
        printf("\nAccount Number: %d", accounts[index].accountNumber);
        printf("\nHolder Name: %s", accounts[index].holderName);
        printf("\nBalance: %.2f\n", accounts[index].balance);
    }
}

void depositMoney() {
    int accNo;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    int index = findAccountIndex(accNo);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Deposit amount must be positive!\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Amount deposited successfully!\n");
    printf("Updated Balance: %.2f\n", accounts[index].balance);
}

void withdrawMoney() {
    int accNo;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    int index = findAccountIndex(accNo);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Withdraw amount must be positive!\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Insufficient balance!\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("Amount withdrawn successfully!\n");
    printf("Updated Balance: %.2f\n", accounts[index].balance);
}

void updateAccountHolderName() {
    int accNo;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    int index = findAccountIndex(accNo);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter New Holder Name: ");
    scanf(" %[^\n]", accounts[index].holderName);

    printf("Account holder name updated successfully!\n");
}

void deleteAccount() {
    int accNo;

    printf("\nEnter Account Number to Delete: ");
    scanf("%d", &accNo);

    int index = findAccountIndex(accNo);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        accounts[i] = accounts[i + 1];
    }

    count--;
    printf("Account deleted successfully!\n");
}

void checkBalance() {
    int accNo;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    int index = findAccountIndex(accNo);

    if (index == -1) {
        printf("Account not found!\n");
    } else {
        printf("Current Balance: %.2f\n", accounts[index].balance);
    }
}

int main() {
    int choice;

    do {
        printf("\n********** Bank Account System **********\n");
        printf("\n1. Add Account");
        printf("\n2. Display All Accounts");
        printf("\n3. Search Account");
        printf("\n4. Deposit Money");
        printf("\n5. Withdraw Money");
        printf("\n6. Update Account Holder Name");
        printf("\n7. Delete Account");
        printf("\n8. Check Balance");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                displayAllAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                depositMoney();
                break;
            case 5:
                withdrawMoney();
                break;
            case 6:
                updateAccountHolderName();
                break;
            case 7:
                deleteAccount();
                break;
            case 8:
                checkBalance();
                break;
            case 9:
                printf("\nThank you for using Bank Account System!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}