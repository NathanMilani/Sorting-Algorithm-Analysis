// Sort2.h : This file contains Sort2 code Declorations
// Class assignment for Program 5
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#pragma once
#include "Sort.h"
#include <iostream>
using namespace std;

class Sort2 : public Sort
{
private:
	int length = 0;
	void recursiveQuickSort(int arr[], int low, int high, int len);
	int partition(int arr[], int low, int high);

	//Save in case we go back to merge sort
	//void merge(int arr[], int middle, int left, int right);
	//void mergeRecursiveSort(int arr[], int left, int right);

public:
	Sort2();
	~Sort2();

	void Sorted(int input[], int output[], int length) override;
	void Print(int output[], int length) override;
};

