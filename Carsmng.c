#include <stdio.h>
#include <string.h>

#define MAX_CARS 100
#define STRING_SIZE 50

// Structure to store car details
typedef struct Car {
    char make[STRING_SIZE];
    char model[STRING_SIZE];
    int year;
    float price;
    float mileage;
} Car;

// Function Prototypes
void addCar(Car cars[], int* count);
void displayCars(const Car cars[], int count);
void searchCars(const Car cars[], int count);

// Main function
int main() {
    Car cars[MAX_CARS];
    int carCount = 0;
    int choice;

    do {
        printf("\n--- Car Dealership Management ---\n");
        printf("1. Add New Car\n");
        printf("2. Display All Cars\n");
        printf("3. Search Cars by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCars(cars, carCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new car
void addCar(Car cars[], int* count) {
    if (*count >= MAX_CARS) {
        printf("Error: Maximum car capacity reached.\n");
        return;
    }

    Car newCar;
    printf("\n--- Add New Car ---\n");
    printf("Enter car make: ");
    scanf(" %[^\n]", newCar.make);
    printf("Enter car model: ");
    scanf(" %[^\n]", newCar.model);
    printf("Enter manufacturing year: ");
    scanf("%d", &newCar.year);
    printf("Enter price: ");
    scanf("%f", &newCar.price);
    printf("Enter mileage: ");
    scanf("%f", &newCar.mileage);

    cars[*count] = newCar;
    (*count)++;

    printf("Car added successfully!\n");
}

// Function to display all cars
void displayCars(const Car cars[], int count) {
    if (count == 0) {
        printf("No cars available in the dealership.\n");
        return;
    }

    printf("\n--- List of Available Cars ---\n");
    for (int i = 0; i < count; i++) {
        printf("Car %d:\n", i + 1);
        printf("  Make: %s\n", cars[i].make);
        printf("  Model: %s\n", cars[i].model);
        printf("  Year: %d\n", cars[i].year);
        printf("  Price: $%.2f\n", cars[i].price);
        printf("  Mileage: %.2f km/l\n", cars[i].mileage);
        printf("---------------------------------\n");
    }
}

// Function to search cars by make or model
void searchCars(const Car cars[], int count) {
    if (count == 0) {
        printf("No cars available to search.\n");
        return;
    }

    char query[STRING_SIZE];
    printf("\nEnter the make or model to search: ");
    scanf(" %[^\n]", query);

    printf("\n--- Search Results ---\n");
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(cars[i].make, query) == 0 || strcmp(cars[i].model, query) == 0) {
            printf("Car %d:\n", i + 1);
            printf("  Make: %s\n", cars[i].make);
            printf("  Model: %s\n", cars[i].model);
            printf("  Year: %d\n", cars[i].year);
            printf("  Price: $%.2f\n", cars[i].price);
            printf("  Mileage: %.2f km/l\n", cars[i].mileage);
            printf("---------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching the query \"%s\".\n", query);
    }
}
