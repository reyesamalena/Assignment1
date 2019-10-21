#ifndef _quicksort_H
#define _quicksort_H
#include <iostream>


using namespace std;
// A utility function to swap two elements
void swap(int* a, int* b);

int partition (int arr[], int low, int high);
  
void quickSort(int arr[], int low, int high);
/* Function to print an array */
void printArray(int arr[], int size);

#endif
  
/* This code is contributed by rathbhupendra from https://www.geeksforgeeks.org/quick-sort/ */
