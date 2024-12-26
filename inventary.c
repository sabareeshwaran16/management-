#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    
    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void removeItem() {
    int id, found = 0;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Item not found!\n");
    }
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    printf("\nInventory Items:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    int id, found = 0;
    printf("Enter item ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            break;
        }
    }
    
    if (!found) {
        printf("Item not found!\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                searchItem();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
