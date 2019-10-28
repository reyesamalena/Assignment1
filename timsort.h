#ifndef timsort_H
#define timsort_H
#include <iostream>
const int RUN = 1000000;

using namespace std;

// this function sorts array from left index to
// to right index which is of size atmost RUN
void tinsertionSort(int arr[], int left, int right);
  
// merge function merges the sorted runs
void tmerge(int arr[], int l, int m, int r);

// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(int arr[], int n);

// utility function to print the Array
void print_TArray(int arr[], int n);


/* code from https://www.geeksforgeeks.org/timsort/ */


#endif
