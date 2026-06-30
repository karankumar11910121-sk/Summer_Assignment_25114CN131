// Q114. WAP to create menu-driven array operations system.

#include <stdio.h>
#define MAX 100

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX], n = 0;
    int choice, pos, value;

    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Update Element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);

                if (n < 0 || n > MAX) {
                    printf("Invalid size. Maximum allowed size is %d.\n", MAX);
                    n = 0;
                } else {
                    printf("Enter %d elements:\n", n);
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &arr[i]);
                    }
                    printf("Array created successfully.\n");
                }
                break;

            case 2:
                display(arr, n);
                break;

            case 3:
                if (n == MAX) {
                    printf("Array is full. Cannot insert.\n");
                } else {
                    printf("Enter position to insert: ");
                    scanf("%d", &pos);

                    if (pos < 1 || pos > n + 1) {
                        printf("Invalid position.\n");
                    } else {
                        printf("Enter value to insert: ");
                        scanf("%d", &value);

                        for (int i = n; i >= pos; i--) {
                            arr[i] = arr[i - 1];
                        }

                        arr[pos - 1] = value;
                        n++;
                        printf("Element inserted successfully.\n");
                    }
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Array is empty. Cannot delete.\n");
                } else {
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);

                    if (pos < 1 || pos > n) {
                        printf("Invalid position.\n");
                    } else {
                        value = arr[pos - 1];

                        for (int i = pos - 1; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }

                        n--;
                        printf("Deleted element: %d\n", value);
                    }
                }
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);

                {
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == value) {
                            printf("Element found at position %d.\n", i + 1);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Element not found.\n");
                    }
                }
                break;

            case 6:
                if (n == 0) {
                    printf("Array is empty. Cannot update.\n");
                } else {
                    printf("Enter position to update: ");
                    scanf("%d", &pos);

                    if (pos < 1 || pos > n) {
                        printf("Invalid position.\n");
                    } else {
                        printf("Enter new value: ");
                        scanf("%d", &value);

                        arr[pos - 1] = value;
                        printf("Element updated successfully.\n");
                    }
                }
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}