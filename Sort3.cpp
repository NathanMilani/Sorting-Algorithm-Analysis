// Sort3.cpp : This file contains code Implementation for the bubble sort algorithm
// Class assignment for Program 5
// Author: Nathan Milani – This is my own work!
// Using compiler MSVS 2022
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "Sort3.h"

// Constructor: Initializes the Sort3 object and displays its details
Sort3::Sort3()
{
    cout << "\n\n\033[32mSort3, Bubble Sort, Nathan Milani\033[0m\n"; // Print information in green text
}

// Destructor: Cleans up the Sort3 object
Sort3::~Sort3()
{
    // No specific cleanup required
}

// Implements the Bubble Sort algorithm to sort the array
// Bubble Sort repeatedly steps through the array, compares adjacent elements, 
// and shifts them until the array is sorted.
void Sort3::Sorted(int input[], int output[], int len)
{
    // Copy the input array to the output array so the original array remains unmodified
    copyArray(input, output, len);

    // Iterate through the array for each sorting pass
    for (int index = 0; index < len - 1; index++)
    {
        // Find the smallest element in the remaining unsorted portion of the array
        int minIndex = findMin(output, index, len);

        // Perform a shift operation to bring the smallest element to its correct position
        shift(output, index, minIndex);

        // If the 'showWork' flag is enabled, display the shift operation and the array's state
        if (GetShowWork())
        {
            cout << "Shifted element " << output[index] << " with " << output[index + 1] << ": ";
            printInfo(output, len); // Print the current state of the array
        }
    }
}

// Prints the final sorted array when sorting is completed
void Sort3::Print(int output[], int len)
{
    cout << left << setw(28) << "Bubble Sort: ";
    printInfo(output, len); // Utilize the base class method to display the array
}

// Helper function: Performs a shift operation
// Moves the element at the 'stop' position to the 'start' position by shifting all elements in between
void Sort3::shift(int output[], int start, int stop)
{
    // Shift elements one position to the right from 'start' to 'stop'
    for (int index = stop; index > start; index--)
    {
        swap(output, index, index - 1); // Swap the current element with the previous one
    }
}
