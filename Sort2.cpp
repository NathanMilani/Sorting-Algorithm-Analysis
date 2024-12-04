// Sor.cpp : This file contains code Implementation for the quick sort algorithm
// Class assignment for Program 5
// Author: Nathan Milani – This is my own work!
// Using compiler MSVS 2022
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "Sort2.h"

// Constructor: Initializes the Sort2 object and displays its details
Sort2::Sort2()
{
    cout << "\n\n\033[32mSort2, Quick sort, Nathan Milani\033[0m\n"; // Print information in green text
}

// Destructor: Cleans up the Sort2 object
Sort2::~Sort2()
{
    // No specific cleanup required
}

// Performs the QuickSort algorithm on the input array and stores the result in the output array
void Sort2::Sorted(int input[], int output[], int len)
{
    // Copy the input array to the output array so the original array remains unmodified
    copyArray(input, output, len);

    // Call the recursive QuickSort function to sort the array
    recursiveQuickSort(output, 0, len - 1, len);
}

// Recursive QuickSort function
// Sorts the portion of the array between indices 'low' and 'high'
void Sort2::recursiveQuickSort(int arr[], int first, int last, int len)
{
    if (first < last) // Base condition: Do nothing if the subarray has 0 or 1 element
    {
        // Partition the array and get the pivot index
        int pivotLocation = partition(arr, first, last);

        // If the 'showWork' flag is enabled, display the pivot value and the array's state after partitioning
        if (GetShowWork())
        {
            cout << "Pivot is: " << arr[pivotLocation] << "; Array after Pivot: ";
            printInfo(arr, len); // Print the array
        }

        // Recursively sort the subarrays to the left and right of the pivot
        recursiveQuickSort(arr, first, pivotLocation - 1, len);   // Left subarray
        recursiveQuickSort(arr, pivotLocation + 1, last, len); // Right subarray
    }
}

// Partitions the array into two sections: elements less than or equal to the pivot
// and elements greater than the pivot
// Returns the pivot's final position in the sorted array
int Sort2::partition(int arr[], int first, int last)
{
    // Swap the pivot element (chosen as the middle element) with the first element
    swap(arr, first, (first + last) / 2);
    
    // Set the pivot and initialize the index for elements less than the pivot
    int pivot = arr[first];
    int lowestIndex = first;

    // Iterate through the array to rearrange elements based on the pivot value
    for (int index = first; index <= last; index++)
    {
        if (arr[index] < pivot)      // If the current element is less than or equal to the pivot
        {
            lowestIndex++;                 // Move the lowest index forward
            swap(arr, lowestIndex, index); // Swap the current element with the element at lowestIndex
        }
    }

    // Place the pivot in its final position by swapping it with the element at lowestIndex
    swap(arr, first, lowestIndex);

    // Return the final position of the pivot
    return lowestIndex;
}

// Prints the sorted array when sorting is completed
void Sort2::Print(int output[], int len)
{
    cout << left << setw(33) << "Quick Sort: ";
    printInfo(output, len); // Utilize the base class method to display the array
}
