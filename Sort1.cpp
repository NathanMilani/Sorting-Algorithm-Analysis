// So.cpp : This file contains code Implementation for the selection sort algorithm
// Class assignment for Program 5
// Author: Nathan Milani – This is my own work!
// Using compiler MSVS 2022
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "Sort1.h"

Sort1::Sort1()
{
	cout << "\033[32mSort1, Selection Sort, Nathan Milani\033[0m\n";
}

Sort1::~Sort1()
{

}

// This function performs the selection sort algorithm. 
// The selection sort will:
// 1). Start at the first element in the array
// 2). Search for the smallest element in the array
// 3). Swap the current element in the array with lowest
// 4). Move to the next element in the array
// 5). Then repate the process
void Sort1::Sorted(int input[], int output[], int len)
{
	// Copying the input array to the output array
	copyArray(input, output, len);

	// This for loop, will increment the index after the sort has completed each of the behaviors stated at the top of the function.
	for (int index = 0; index < len - 1; index++)
	{
		// holder variable to perform the findMin function. This will  find the minimum value in the array
		int minIndex = findMin(output, index, len);

		// Swaps the current index and the minimum value in the array
		swap(output, index, minIndex);

		// Shows the behavior of the sort being done to sort the array when turned on in the CS221Program5 file
		if (GetShowWork())
		{
			cout << "Swapping element " << output[index] << " with " << output[minIndex] << ": ";
			printInfo(output, len);
		}
	}
}

// Prints the sorted array when completed  
void Sort1::Print(int output[], int len)
{
	cout << left << setw(29) << "Selection Sort: ";
	printInfo(output, len);
}