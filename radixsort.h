#ifndef radixsort_H
#define radixsort_H
#include<iostream>

using namespace std;
  
// A utility function to get maximum value in arr[]
int getMax( int arr[], int n);
  
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp);
  
// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n);
  
// A utility function to print an array
void print(int arr[], int n);
/* code from https://www.geeksforgeeks.org/radix-sort/ */

#endif
  
