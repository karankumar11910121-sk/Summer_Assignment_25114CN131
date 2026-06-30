// Q118. WAP to create mini library system.

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued;
};

void addBook(struct Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("\nLibrary is full. Cannot add more books.\n");
        return;
    }

    printf("\nEnter book ID: ");
    scanf("%d", &books[*count].id);
    getchar();

    printf("Enter book title: ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = '\0';

    printf("Enter author name: ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = '\0';

    books[*count].isIssued = 0;
    (*count)++;

    printf("\nBook added successfully.\n");
}

void displayBooks(struct Book books[], int count) {
    int i;

    if (count == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-10s\n", "Book ID", "Title", "Author", "Status");
    printf("----------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-10d %-30s %-25s %-10s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].isIssued ? "Issued" : "Available");
    }
}

int findBookById(struct Book books[], int count, int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            return i;
        }
    }

    return -1;
}

void searchBook(struct Book books[], int count) {
    int id, index;

    printf("\nEnter book ID to search: ");
    scanf("%d", &id);

    index = findBookById(books, count, id);

    if (index == -1) {
        printf("\nBook not found.\n");
    } else {
        printf("\nBook found:\n");
        printf("Book ID: %d\n", books[index].id);
        printf("Title: %s\n", books[index].title);
        printf("Author: %s\n", books[index].author);
        printf("Status: %s\n", books[index].isIssued ? "Issued" : "Available");
    }
}

void issueBook(struct Book books[], int count) {
    int id, index;

    printf("\nEnter book ID to issue: ");
    scanf("%d", &id);

    index = findBookById(books, count, id);

    if (index == -1) {
        printf("\nBook not found.\n");
    } else if (books[index].isIssued) {
        printf("\nBook is already issued.\n");
    } else {
        books[index].isIssued = 1;
        printf("\nBook issued successfully.\n");
    }
}

void returnBook(struct Book books[], int count) {
    int id, index;

    printf("\nEnter book ID to return: ");
    scanf("%d", &id);

    index = findBookById(books, count, id);

    if (index == -1) {
        printf("\nBook not found.\n");
    } else if (!books[index].isIssued) {
        printf("\nThis book was not issued.\n");
    } else {
        books[index].isIssued = 0;
        printf("\nBook returned successfully.\n");
    }
}

int main() {
    struct Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\n***** Mini Library System *****\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                issueBook(books, count);
                break;
            case 5:
                returnBook(books, count);
                break;
            case 6:
                printf("\nThank you for using the Mini Library System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}