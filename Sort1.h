// Sort1.h : This file contains Sort1 code Declorations
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

class Sort1 : public Sort
{	
public:
	Sort1();
	~Sort1();

	void Sorted(int input[], int output[], int len) override;
	void Print(int output[], int len) override;
};


