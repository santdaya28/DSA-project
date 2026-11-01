
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing station details
struct Station {
    char name[50];
    char arrivalTime[20];
    struct Station *next;
};

// Head pointer of linked list
struct Station *head = NULL;

// Function to add a station
void addStation() {
    struct Station *newStation, *temp;

    newStation = (struct Station *)malloc(sizeof(struct Station));

    if (newStation == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Station Name: ");
    scanf(" %[^\n]", newStation->name);

    printf("Enter Arrival Time (HH:MM): ");
    scanf("%19s", newStation->arrivalTime);

    newStation->next = NULL;

    if (head == NULL) {
        head = newStation;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newStation;
    }

    printf("\nStation added successfully!\n");
}

// Function to display complete journey
void displayJourney() {
    struct Station *temp = head;

    if (head == NULL) {
        printf("\nNo journey records found!\n");
        return;
    }

    printf("\n========== TRAIN JOURNEY ==========\n");

    int count = 1;

    while (temp != NULL) {
        printf("%d. Station: %s\n", count, temp->name);
        printf("   Arrival Time: %s\n", temp->arrivalTime);

        temp = temp->next;
        count++;
    }

    printf("===================================\n");
}

// Function to search a station
void searchStation() {
    struct Station *temp = head;
    char searchName[50];
    int found = 0;

    printf("Enter station name to search: ");
    scanf(" %[^\n]", searchName);

    while (temp != NULL) {
        if (strcmp(temp->name, searchName) == 0) {
            printf("\nStation Found!\n");
            printf("Station Name: %s\n", temp->name);
            printf("Arrival Time: %s\n", temp->arrivalTime);
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (!found) {
        printf("\nStation not found!\n");
    }
}

// Function to show current location
void currentLocation() {
    struct Station *temp = head;

    if (head == NULL) {
        printf("\nNo journey started yet!\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nCurrent Recorded Location: %s\n", temp->name);
    printf("Arrival Time: %s\n", temp->arrivalTime);
}

// Function to free allocated memory
void freeMemory() {
    struct Station *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n================================\n");
        printf("       TRAIN JOURNEY TRACKER\n");
        printf("================================\n");
        printf("1. Add Station\n");
        printf("2. Display Complete Journey\n");
        printf("3. Search Station\n");
        printf("4. Show Current Recorded Location\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStation();
                break;

            case 2:
                displayJourney();
                break;

            case 3:
                searchStation();
                break;

            case 4:
                currentLocation();
                break;

            case 5:
                freeMemory();
                printf("\nThank you for using Train Journey Tracker!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
