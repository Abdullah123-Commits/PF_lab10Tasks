#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 10
#define STRING_SIZE 50

// Structure to store travel package details
typedef struct TravelPackage {
    char packageName[STRING_SIZE];
    char destination[STRING_SIZE];
    int duration;  // in days
    float cost;    // per person
    int seatsAvailable;
} TravelPackage;

// Function Prototypes
void displayPackages(const TravelPackage packages[], int count);
void bookPackage(TravelPackage packages[], int count);
void addPackage(TravelPackage packages[], int* count);

int main() {
    TravelPackage packages[MAX_PACKAGES];
    int packageCount = 0;
    int choice;

    // Add some sample packages
    addPackage(packages, &packageCount);

    do {
        printf("\n--- Travel Agency ---\n");
        printf("1. Display Available Travel Packages\n");
        printf("2. Book a Travel Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages(packages, packageCount);
                break;
            case 2:
                bookPackage(packages, packageCount);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to display all available travel packages
void displayPackages(const TravelPackage packages[], int count) {
    if (count == 0) {
        printf("No packages available.\n");
        return;
    }

    printf("\n--- Available Travel Packages ---\n");
    for (int i = 0; i < count; i++) {
        printf("Package %d:\n", i + 1);
        printf("  Name: %s\n", packages[i].packageName);
        printf("  Destination: %s\n", packages[i].destination);
        printf("  Duration: %d days\n", packages[i].duration);
        printf("  Cost: $%.2f per person\n", packages[i].cost);
        printf("  Seats Available: %d\n", packages[i].seatsAvailable);
        printf("---------------------------------\n");
    }
}

// Function to book a travel package
void bookPackage(TravelPackage packages[], int count) {
    if (count == 0) {
        printf("No packages available to book.\n");
        return;
    }

    int packageChoice, numberOfSeats;

    printf("\nEnter the package number you want to book: ");
    scanf("%d", &packageChoice);

    if (packageChoice < 1 || packageChoice > count) {
        printf("Invalid package choice. Please try again.\n");
        return;
    }

    printf("Enter number of seats to book: ");
    scanf("%d", &numberOfSeats);

    if (numberOfSeats > packages[packageChoice - 1].seatsAvailable) {
        printf("Not enough seats available. Please choose a smaller number of seats.\n");
        return;
    }

    packages[packageChoice - 1].seatsAvailable -= numberOfSeats;
    printf("Booking successful! You have booked %d seats for the '%s' package.\n", numberOfSeats, packages[packageChoice - 1].packageName);
}

// Function to add a new travel package
void addPackage(TravelPackage packages[], int* count) {
    if (*count >= MAX_PACKAGES) {
        printf("Error: Maximum package capacity reached.\n");
        return;
    }

    TravelPackage newPackage;

    printf("\nEnter travel package name: ");
    scanf(" %[^\n]", newPackage.packageName);
    printf("Enter destination: ");
    scanf(" %[^\n]", newPackage.destination);
    printf("Enter duration (in days): ");
    scanf("%d", &newPackage.duration);
    printf("Enter cost per person: ");
    scanf("%f", &newPackage.cost);
    printf("Enter number of seats available: ");
    scanf("%d", &newPackage.seatsAvailable);

    packages[*count] = newPackage;
    (*count)++;
    printf("New package added successfully!\n");
}
