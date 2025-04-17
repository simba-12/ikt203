# Randomized QuickSort Implementation - ReadMe

## Overview
This C++ application implements the QuickSort algorithm with a randomized pivot selection strategy. The program allows users to input a set of floating-point numbers, sorts them using the randomized QuickSort algorithm, and displays the sorted array.

## Features
1. **Randomized Pivot Selection**:
   - Selects a random pivot for each partition, improving average-case performance
   - Reduces the likelihood of worst-case scenarios common in standard QuickSort

2. **Dynamic Memory Management**:
   - Uses dynamic memory allocation to handle arrays of arbitrary size
   - Properly frees allocated memory to prevent memory leaks

3. **Input Validation**:
   - Validates that the array size is positive
   - Ensures all inputs are valid numeric values

4. **User Interaction**:
   - Prompts the user for the number of elements
   - Accepts input for each element
   - Displays the sorted array

## How to Run the Program
1. Ensure you have a C++ compiler installed.
2. Compile the program using the command:
   ```bash
   g++ -o quicksort quicksort.cpp
   ```
3. Run the compiled program:
   ```bash
   ./quicksort
   ```

## Implementation Details
- The randomized QuickSort algorithm has an average time complexity of O(n log n).
- The pivot selection is randomized to avoid worst-case scenarios of O(n²).
- The implementation uses in-place partitioning to minimize memory usage.

## Usage
When you run the program:
1. Enter the number of elements to sort
2. Enter each element separated by spaces
3. The program will display the sorted array
