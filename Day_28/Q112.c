// Q112. WAP to create contact management system.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 20
#define EMAIL_LEN 50
#define ADDRESS_LEN 100

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
    char address[ADDRESS_LEN];
} Contact;

void removeNewline(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}

void readLine(char prompt[], char value[], int size) {
    printf("%s", prompt);
    fgets(value, size, stdin);
    removeNewline(value);
}

int isEmpty(char value[]) {
    return strlen(value) == 0;
}

int isValidPhone(char phone[]) {
    int i;
    int len = strlen(phone);

    if (len < 10 || len >= PHONE_LEN) {
        return 0;
    }

    for (i = 0; i < len; i++) {
        if (!isdigit((unsigned char)phone[i])) {
            return 0;
        }
    }

    return 1;
}

int isValidEmail(char email[]) {
    char *at = strchr(email, '@');
    char *dot = strrchr(email, '.');

    if (isEmpty(email)) {
        return 0;
    }

    return at != NULL && dot != NULL && at < dot;
}

int findContact(Contact contacts[], int count, char name[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

int findContactByPhone(Contact contacts[], int count, char phone[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].phone, phone) == 0) {
            return i;
        }
    }

    return -1;
}

void inputValidContact(Contact contacts[], int count, Contact *contact, int currentIndex) {
    int duplicateIndex;

    do {
        readLine("Enter name: ", contact->name, NAME_LEN);
        if (isEmpty(contact->name)) {
            printf("Name cannot be empty.\n");
        }
    } while (isEmpty(contact->name));

    do {
        readLine("Enter phone number: ", contact->phone, PHONE_LEN);
        duplicateIndex = findContactByPhone(contacts, count, contact->phone);

        if (!isValidPhone(contact->phone)) {
            printf("Phone number must contain only digits and should be at least 10 digits.\n");
        } else if (duplicateIndex != -1 && duplicateIndex != currentIndex) {
            printf("Duplicate phone number found. Please enter a different phone number.\n");
        }
    } while (!isValidPhone(contact->phone) ||
             (findContactByPhone(contacts, count, contact->phone) != -1 &&
              findContactByPhone(contacts, count, contact->phone) != currentIndex));

    do {
        readLine("Enter email: ", contact->email, EMAIL_LEN);
        if (!isValidEmail(contact->email)) {
            printf("Invalid email. Please enter a valid email address.\n");
        }
    } while (!isValidEmail(contact->email));

    do {
        readLine("Enter address: ", contact->address, ADDRESS_LEN);
        if (isEmpty(contact->address)) {
            printf("Address cannot be empty.\n");
        }
    } while (isEmpty(contact->address));
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("\nContact list is full.\n");
        return;
    }

    printf("\n--- Add Contact ---\n");
    inputValidContact(contacts, *count, &contacts[*count], -1);

    (*count)++;
    printf("Contact added successfully.\n");
}

void displayOneContact(Contact contact) {
    printf("Name   : %s\n", contact.name);
    printf("Phone  : %s\n", contact.phone);
    printf("Email  : %s\n", contact.email);
    printf("Address: %s\n", contact.address);
}

void displayContacts(Contact contacts[], int count) {
    int i;

    if (count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (i = 0; i < count; i++) {
        printf("\nContact %d\n", i + 1);
        displayOneContact(contacts[i]);
    }
}

void showTotalContacts(int count) {
    printf("\nTotal contacts: %d\n", count);
}

void searchContact(Contact contacts[], int count) {
    char name[NAME_LEN];
    int index;

    printf("\n--- Search Contact By Name ---\n");
    readLine("Enter name to search: ", name, NAME_LEN);

    index = findContact(contacts, count, name);
    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        printf("\nContact found:\n");
        displayOneContact(contacts[index]);
    }
}

void searchContactByPhone(Contact contacts[], int count) {
    char phone[PHONE_LEN];
    int index;

    printf("\n--- Search Contact By Phone ---\n");
    readLine("Enter phone number to search: ", phone, PHONE_LEN);

    index = findContactByPhone(contacts, count, phone);
    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        printf("\nContact found:\n");
        displayOneContact(contacts[index]);
    }
}

void updateContact(Contact contacts[], int count) {
    char name[NAME_LEN];
    int index;

    printf("\n--- Update Contact ---\n");
    readLine("Enter name to update: ", name, NAME_LEN);

    index = findContact(contacts, count, name);
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    inputValidContact(contacts, count, &contacts[index], index);

    printf("Contact updated successfully.\n");
}

void deleteContact(Contact contacts[], int *count) {
    char name[NAME_LEN];
    int index;
    int i;

    printf("\n--- Delete Contact ---\n");
    readLine("Enter name to delete: ", name, NAME_LEN);

    index = findContact(contacts, *count, name);
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    (*count)--;
    printf("Contact deleted successfully.\n");
}

void sortContactsByName(Contact contacts[], int count) {
    int i;
    int j;
    Contact temp;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(contacts[j].name, contacts[j + 1].name) > 0) {
                temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }

    printf("\nContacts sorted by name successfully.\n");
}

void saveContacts(Contact contacts[], int count) {
    FILE *fp;
    int i;

    fp = fopen("contacts.txt", "w");
    if (fp == NULL) {
        printf("Unable to save contacts.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%s\n%s\n%s\n%s\n",
                contacts[i].name,
                contacts[i].phone,
                contacts[i].email,
                contacts[i].address);
    }

    fclose(fp);
}

void loadContacts(Contact contacts[], int *count) {
    FILE *fp;

    fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        return;
    }

    while (*count < MAX_CONTACTS &&
           fgets(contacts[*count].name, NAME_LEN, fp) != NULL &&
           fgets(contacts[*count].phone, PHONE_LEN, fp) != NULL &&
           fgets(contacts[*count].email, EMAIL_LEN, fp) != NULL &&
           fgets(contacts[*count].address, ADDRESS_LEN, fp) != NULL) {
        removeNewline(contacts[*count].name);
        removeNewline(contacts[*count].phone);
        removeNewline(contacts[*count].email);
        removeNewline(contacts[*count].address);
        (*count)++;
    }

    fclose(fp);
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    loadContacts(contacts, &count);

    do {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact By Name\n");
        printf("4. Search Contact By Phone\n");
        printf("5. Update Contact\n");
        printf("6. Delete Contact\n");
        printf("7. Show Total Contacts\n");
        printf("8. Sort Contacts By Name\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                saveContacts(contacts, count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                searchContactByPhone(contacts, count);
                break;
            case 5:
                updateContact(contacts, count);
                saveContacts(contacts, count);
                break;
            case 6:
                deleteContact(contacts, &count);
                saveContacts(contacts, count);
                break;
            case 7:
                showTotalContacts(count);
                break;
            case 8:
                sortContactsByName(contacts, count);
                saveContacts(contacts, count);
                break;
            case 9:
                saveContacts(contacts, count);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
       } while (choice != 9);

    return 0;
}