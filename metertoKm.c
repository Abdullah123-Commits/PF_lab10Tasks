#include <stdio.h>

// Define a constant for the conversion factor
#define METERS_TO_KM 0.001

// Function prototype
float convertToKilometers(float meters);
void functionCallCount(void);

// Static variable to count function calls
static int callCount = 0;

int main() {
    float meters;

    // Example for conversion
    printf("Enter distance in meters: ");
    scanf("%f", &meters);
    
    float kilometers = convertToKilometers(meters);
    printf("%.2f meters is equal to %.2f kilometers.\n", meters, kilometers);

    // Function call count demonstration
    // functionCallCount();
    // functionCallCount();
    // functionCallCount();

    return 0;
}

// Function to convert meters to kilometers
float convertToKilometers(float meters) {
    functionCallCount();
    return meters * METERS_TO_KM;
}

// Function to count how many times it has been called
void functionCallCount(void) {
    callCount++;
    printf("The function has been called %d time(s).\n", callCount);
}
