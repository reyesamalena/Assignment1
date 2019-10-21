#ifndef _optquicksort_H
#define _optquicksort_H
#include <iostream>
#include "optquicksort.h"
#include <iostream>

using namespace std;

// perform insertion sort on arr[]
void OinsertionSort(int arr[], int low, int n);
 
int OPartition (int a[], int low, int high);


void optimizedQuickSort(int A[], int low, int high);
/* code from https://www.techiedelight.com/hybrid-quicksort/ */

void printOQarray(int a[], int size);
#endif


