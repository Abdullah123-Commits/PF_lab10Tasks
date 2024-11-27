#include <stdio.h>

// Recursive function to perform linear search and print all indices where the target is found
void linearSearch(int arr[], int size, int target, int index) {
    // Base case: if index is equal to the size of the array, return
    if (index == size) {
        return;
    }

    // If the target is found at the current index, print the index
    if (arr[index] == target) {
        printf("Element %d found at index %d.\n", target, index);
    }

    // Recursive case: search in the next index
    linearSearch(arr, size, target, index + 1);
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Get the target element to search for
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Start the recursive search from the 0th index
    linearSearch(arr, size, target, 0);

    return 0;
}
