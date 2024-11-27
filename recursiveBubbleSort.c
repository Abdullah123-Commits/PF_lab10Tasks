#include <stdio.h>

#define SIZE 20

// Function to perform bubble sort based on recursion
void bubbleSort(int arr[], int arraySize, int currentIndex) {
    // Base case: if the size is 1 or we have completed a full pass without any swaps
    if (arraySize == 1) {
        return;
    }

    //  To Perform a single pass of bubble sort
    if (currentIndex < arraySize - 1) {
        if (arr[currentIndex] > arr[currentIndex + 1]) {
            // Swap if elements are in the wrong order
            int temp = arr[currentIndex];
            arr[currentIndex] = arr[currentIndex + 1];
            arr[currentIndex + 1] = temp;
        }

        // Recursive call for the next pair
        bubbleSort(arr, arraySize, currentIndex + 1);
    }
    else {
        // If we have completed a pass, reduce the array size and start again
        bubbleSort(arr, arraySize - 1, 0);
    }
}

// Function to print the array
void printArray(int arr[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];

    printf("Enter %d elements for the array:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, SIZE, 0);

    printf("\nSorted array: ");
    printArray(arr, SIZE);

    return 0;
}
