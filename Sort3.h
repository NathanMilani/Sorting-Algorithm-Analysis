// Sort3.h : This file contains Sort3 code Declorations
// Class assignment for Program 5
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#pragma once
#include "Sort.h"

class Sort3 : public Sort
{
private:
	void shift(int output[], int start, int stop);

public:
	Sort3();
	~Sort3();

	void Sorted(int input[], int output[], int len) override;
	void Print(int array[], int len) override;
};

