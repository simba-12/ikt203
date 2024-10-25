

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For clock() and time()
#include <algorithm>
using namespace std;

// Choosen at random Sorting quickly
int pivotRandomlydiveded(float array[], int thelower, int thehigher) {
    int randomIndex = thelower + rand() % (thehigher - thelower + 1);  // Randomly choose a pivot
    swap(array[randomIndex], array[thehigher]);  // Move the pivot to the last element.

    float pivot = array[thehigher];  // Use the last element as the pivot
    int i = thelower - 1;  // Index of smaller element

    // Move things to the left that are smaller than the center.
    for (int j = thelower; j < thehigher; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);  // in this line will swap the smaller element with on the left
        }
    }

    // Place pivot in its correct position.
    swap(array[i + 1], array[thehigher]);
    return i + 1;  // Return the pivot's final position
}

// What the function is Randomized Quick Sort Split the array into
void quicksort(float array[], int thelower, int thehigher) {
    if (thelower < thehigher) {
        int pi = pivotRandomlydiveded(array, thelower, thehigher);  // Partition the array
        quicksort(array, thelower, pi - 1);  // Sort the left subarray
        quicksort(array, pi + 1, thehigher);  // Sort the right subarray
    }
}

// Function to print the sorted array
void displaySortedArray(float array[], int n) {
    cout << "Randomized Quick Sort sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Seed for random number generator

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Check if array size is valid
    if (n <= 0) {
        cout << "Error: The array size must be greater than zero!" << endl;
        return 1;
    }

    // Dynamically allocate the array to avoid stack overflow
    float* array = new float[n];
    cout << "Please enter exactly " << n << " elements separated by spaces: ";

    // Input validation for numeric values
    for (int i = 0; i < n; i++) {
        if (!(cin >> array[i])) {
            cout << "Error: Invalid input. Please enter numeric values only!" << endl;
            delete[] array;  // Free the memory before exiting
            return 1;
        }
    }

    // Call sorting function
    quicksort(array, 0, n - 1);
    displaySortedArray(array, n);  // Display the sorted array

    // Free the allocated memory
    delete[] array;

    return 0;  // End the program
}
