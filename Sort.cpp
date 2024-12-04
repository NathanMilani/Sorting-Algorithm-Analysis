// Sort.cpp : This file contains code Implementation for all the default and helper functions for the derived classes
// Class assignment for Program 5
// Author: Nathan Milani – This is my own work!
// Using compiler MSVS 2022
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "Sort.h"
Sort::Sort()
{

}

Sort::~Sort()
{

}

void Sort::SetShowWork(bool setWork)
{
	showWork = setWork;
}

bool Sort::GetShowWork()
{
	return showWork;
}

// *******************************************************
// Base class helper functions for Sort1, Sort2, and Sort3
// *******************************************************

// Goes through the array and prints the sorted order of each of the derived classes
void Sort::printInfo(int output[], int length)
{
	cout << "{ ";
	for (int index = 0; index < length; index++)
	{
		cout << output[index] << " ";
	}
	cout << "}" << endl;
}

// Copies the input array into the output array for all of the derived classes
void Sort::copyArray(int input[], int output[], int len)
{
	for (int index = 0; index < len; index++)
	{
		output[index] = input[index];
	}

	if (GetShowWork()) 
	{
		cout << "Original array: ";
		printInfo(output, len);
	}
}

// Finds the minimum value in the array for Sort1 and Sort3
int Sort::findMin(int output[], int start, int len)
{
	int minIndex = start;
	for (int element = start; element < len; element++)
	{
		if (output[element] < output[minIndex])
		{
			minIndex = element;
		}
	}

	return minIndex;
}

// Swaps certain elements in the array for all three derived classes
void Sort::swap(int output[], int first, int second)
{
	int temperary = output[first];
	output[first] = output[second];
	output[second] = temperary;
}