// CS221Program5.cpp : This file contains the code Implementation to test the behavior and time of each sorting algorithm
// Class assignment for Program 5
// Author: Nathan Milani – This is my own work!
// Using compiler MSVS 2022
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "Sort1.h"
#include "Sort2.h"
#include "Sort3.h"
#include <cstdlib>
#include <chrono>
using namespace std::chrono;

// Helper function declorations.
void generateNumbers(int arr[], int size);
void sortIt(Sort& sorter, int Array[], int arrayOut[], int length);
void calculateTime(Sort& sorter, int input[], int output[], int length, int repetition);


int main()
{
    // Demonstration arrays and variable to showcase the sorts behavior
    int demonstrationList[] = { 32, 55, 87, 13, 78, 96, 52, 48, 22, 11, 58, 66,88, 45 };
    int demonstrationOutput[14];
    int demonstrationLength = 14;

    // Timing arrays and variables for showing the time it took to calculate each sorts time of a dataset of size 1000
    int timingList[1000];
    int timingLength = 1000;
    int timingOutput[1000];
    int repetition = 100;

    // Used to generate the elements in timingList and give it random numbers each time from 0 up to 999
    // 0 up to 999 in theory is 1000 elements because we start from 0 and go up to 999.
    generateNumbers(timingList, timingLength);


    // ****Sort1: Demonstrating Selection Sort****
    Sort1 selection;
    cout << "Demonstration of Selection Sort\n";
    sortIt(selection, demonstrationList, demonstrationOutput, demonstrationLength);

    // Sort1: Timing the Selection sort with a large scale dataset
    cout << "\n\033[32mTime it took for selection sort with a large size of data: \033[0m";
    calculateTime(selection, timingList, timingOutput, timingLength, repetition);
    system("pause");



    // ****Sort2: Demonstrating Quick Sort****
    Sort2 quick;
    cout << "Demonstration of Quick Sort\n";
    sortIt(quick, demonstrationList, demonstrationOutput, demonstrationLength);

    // Sort2: Timing the quick sort with a large scale dataset
    cout << "\n\033[32mTime it took for quick sort with a large size of data: \033[0m";
    calculateTime(quick, timingList, timingOutput, timingLength, repetition);
    system("pause");



    // ****Sort3: Demonstrating Bubble Sort****
    Sort3 bubble;
    cout << "Demonstration of Bubble Sort\n";
    sortIt(bubble, demonstrationList, demonstrationOutput, demonstrationLength);

    // Sort2: Timing the bubble sort with a large scale dataset
    cout << "\n\033[32mTime it took for bubble sort with a large size of data: \033[0m";
    calculateTime(bubble, timingList, timingOutput, timingLength, repetition);
    system("pause");

    return 0;
}

void generateNumbers(int arr[], int size)
{
    // Generates a certian number of elements in the array between the numbers 0 and 999 into the timingList array.
    // Keeps adding numbers as long as the index is less than the timingLength
    for (int index = 0; index < size; index++)
    {
        arr[index] = rand() % 1000;
    }
}

// Performs the sorting behavior of the demonstration array to show how the sorting algorithm behaves
void sortIt(Sort& sorter, int Array[], int arrayOut[], int length)
{
    sorter.SetShowWork(true); // or false, as I choose during testing
    sorter.Sorted(Array, arrayOut, length);
    sorter.Print(arrayOut, length);
}

// Calculates the time of the timing array to test the time complexity of each sorting algorithm.
void calculateTime(Sort& sorter, int input[], int output[], int length, int repetition)
{
    sorter.SetShowWork(false);

    // Start the timer
    auto start_Sorting = system_clock::now();

    // Perform the sort multiple times
    for (int index = 0; index < length; index++)
    {
        sorter.Sorted(input, output, length);
    }

    // Stop the timer
    auto stop_Sorting = system_clock::now();

    // Calculate duration
    duration<double> sorting_Time = stop_Sorting - start_Sorting;

    // Output results
    cout << "\n\033[32mTiming Results:\033[0m\n";
    cout << "Total Time            Avg. Time Per Sort\n";
    cout << "------------------------------------------\n";
    cout << sorting_Time.count() << " seconds          " << sorting_Time.count() / repetition << " seconds\n\n";
}