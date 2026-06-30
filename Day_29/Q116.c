// Q116. WAP to create inventory management system.

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_SIZE 50

typedef struct {
    int id;
    char name[NAME_SIZE];
    int quantity;
    float price;
} Item;

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int findItemIndex(Item items[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addItem(Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("\nInventory is full. Cannot add more items.\n");
        return;
    }

    Item newItem;

    printf("\nEnter item ID: ");
    scanf("%d", &newItem.id);

    if (findItemIndex(items, *count, newItem.id) != -1) {
        printf("Item with this ID already exists.\n");
        return;
    }

    clearInputBuffer();
    printf("Enter item name: ");
    fgets(newItem.name, NAME_SIZE, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    items[*count] = newItem;
    (*count)++;

    printf("Item added successfully.\n");
}

void displayItems(Item items[], int count) {
    if (count == 0) {
        printf("\nNo items available in inventory.\n");
        return;
    }

    printf("\n%-10s %-25s %-10s %-10s %-10s\n", "ID", "Name", "Quantity", "Price", "Value");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        float value = items[i].quantity * items[i].price;
        printf("%-10d %-25s %-10d %-10.2f %-10.2f\n",
               items[i].id,
               items[i].name,
               items[i].quantity,
               items[i].price,
               value);
    }
}

void searchItem(Item items[], int count) {
    int id;

    printf("\nEnter item ID to search: ");
    scanf("%d", &id);

    int index = findItemIndex(items, count, id);

    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    printf("\nItem found:\n");
    printf("ID       : %d\n", items[index].id);
    printf("Name     : %s\n", items[index].name);
    printf("Quantity : %d\n", items[index].quantity);
    printf("Price    : %.2f\n", items[index].price);
}

void updateItem(Item items[], int count) {
    int id;

    printf("\nEnter item ID to update: ");
    scanf("%d", &id);

    int index = findItemIndex(items, count, id);

    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    clearInputBuffer();
    printf("Enter new item name: ");
    fgets(items[index].name, NAME_SIZE, stdin);
    items[index].name[strcspn(items[index].name, "\n")] = '\0';

    printf("Enter new quantity: ");
    scanf("%d", &items[index].quantity);

    printf("Enter new price: ");
    scanf("%f", &items[index].price);

    printf("Item updated successfully.\n");
}

void deleteItem(Item items[], int *count) {
    int id;

    printf("\nEnter item ID to delete: ");
    scanf("%d", &id);

    int index = findItemIndex(items, *count, id);

    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        items[i] = items[i + 1];
    }

    (*count)--;
    printf("Item deleted successfully.\n");
}

void showTotalValue(Item items[], int count) {
    float total = 0;

    for (int i = 0; i < count; i++) {
        total += items[i].quantity * items[i].price;
    }

    printf("\nTotal inventory value: %.2f\n", total);
}

int main(void) {
    Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    do {
        printf("\n========== Inventory Management System ==========\n");
        printf("1. Add item\n");
        printf("2. Display all items\n");
        printf("3. Search item\n");
        printf("4. Update item\n");
        printf("5. Delete item\n");
        printf("6. Show total inventory value\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                displayItems(items, count);
                break;
            case 3:
                searchItem(items, count);
                break;
            case 4:
                updateItem(items, count);
                break;
            case 5:
                deleteItem(items, &count);
                break;
            case 6:
                showTotalValue(items, count);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}