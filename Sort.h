// Sort.h : This file contains Sort code Declorations
// Class assignment for Program 5
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Sort
{
private:
	bool showWork = false;

protected:
	void printInfo(int output[], int length);
	void copyArray(int input[], int output[], int len);
	int findMin(int output[], int start, int len);
	void swap(int output[], int first, int second);

public:
	Sort();
	~Sort();

	void SetShowWork(bool setWork);
	bool GetShowWork();
	virtual void Sorted(int input[], int output[], int len) = 0;
	virtual void Print(int output[], int len) = 0;
};

