// Q109. WAP to create library management system.

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
struct Book 
{
    int id;
    char title[50];
    char author[50];
    int isIssued;
};

void removeNewline(char text[]) 
{
    int length = strlen(text);

    if (length > 0 && text[length - 1] == '\n') 
    {
        text[length - 1] = '\0';
    }
}

int findBookById(struct Book books[], int count, int id) 
{
    int i;

    for (i = 0; i < count; i++) 
    {
        if (books[i].id == id) 
        {
            return i;
        }
    }

    return -1;
}

void addBook(struct Book books[], int *count) 
{
    int id;

    if (*count >= MAX_BOOKS) 
    {
        printf("\nLibrary is full. Cannot add more books.\n");
        return;
    }

    printf("\nEnter book ID: ");
    scanf("%d", &id);
    getchar();

    if (findBookById(books, *count, id) != -1) 
    {
        printf("A book with this ID already exists.\n");
        return;
    }

    books[*count].id = id;

    printf("Enter book title: ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    removeNewline(books[*count].title);

    printf("Enter author name: ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    removeNewline(books[*count].author);

    books[*count].isIssued = 0;
    (*count)++;

    printf("Book added successfully.\n");
}

void displayBooks(struct Book books[], int count) 
{
    int i;
    if (count == 0) 
    {
        printf("\nNo books are available in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-10s\n", "Book ID", "Title", "Author", "Status");
    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) 
    {
        printf("%-10d %-30s %-25s %-10s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].isIssued ? "Issued" : "Available");
    }
}

void searchBook(struct Book books[], int count) 
{
    int id;
    int index;

    printf("\nEnter book ID to search: ");
    scanf("%d", &id);

    index = findBookById(books, count, id);

    if (index == -1) 
    {
        printf("Book not found.\n");
        return;
    }

    printf("\nBook found:\n");
    printf("Book ID: %d\n", books[index].id);
    printf("Title: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Status: %s\n", books[index].isIssued ? "Issued" : "Available");
}

void issueBook(struct Book books[], int count) 
{
    int id;
    int index;

    printf("\nEnter book ID to issue: ");
    scanf("%d", &id);

    index = findBookById(books, count, id);

    if (index == -1) 
    {
        printf("Book not found.\n");
    } else if (books[index].isIssued) 
    {
        printf("This book is already issued.\n");
    } else 
    {
        books[index].isIssued = 1;
        printf("Book issued successfully.\n");
    }
}

void returnBook(struct Book books[], int count) 
{
    int id;
    int index;
    printf("\nEnter book ID to return: ");
    scanf("%d", &id);

    index = findBookById(books, count, id);

    if (index == -1) 
    {
        printf("Book not found.\n");
    } else if (!books[index].isIssued) 
    {
        printf("This book was not issued.\n");
    } else 
    {
        books[index].isIssued = 0;
        printf("Book returned successfully.\n");
    }
}

int main() 
{
    struct Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\n***** Library Management System *****\n\n");
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
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}