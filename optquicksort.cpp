#include "optquicksort.h"
#include <iostream>

using namespace std;

// perform insertion sort on arr[]
void OinsertionSort(int arr[], int low, int n)
{
    // Start from second element (element at index 0
    // is already sorted)
    for (int i = low + 1; i <= n; i++)
    {
        int value = arr[i];
        int j = i;
        
        // Find the index j within the sorted subset arr[0..i-1]
        // where element arr[i] belongs
        while (j > low && arr[j - 1] > value)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        // Note that subarray arr[j..i-1] is shifted to
        // the right by one position i.e. arr[j+1..i]
        
        arr[j] = value;
    }
}
 
int OPartition (int a[], int low, int high)
{
    // Pick rightmost element as pivot from the array
    int pivot = a[high];

    // elements less than pivot will be pushed to the left of pIndex
    // elements more than pivot will be pushed to the right of pIndex
    // equal elements can go either way
    int pIndex = low;
    
    // each time we finds an element less than or equal to pivot, pIndex
    // is incremented and that element would be placed before the pivot.
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    // swap pIndex with Pivot
    swap (a[pIndex], a[high]);
    
    // return pIndex (index of pivot element)
    return pIndex;
}


void optimizedQuickSort(int A[], int low, int high)
{
    while (low < high)
    {
        // do insertion sort if 10 or smaller
        if(high - low < 10)
        {
            OinsertionSort(A, low, high);
            break;
        }
        else
        {
            int pivot = OPartition(A, low, high);
            
            // tail call optimizations - recur on smaller sub-array
            if (pivot - low < high - pivot) {
                optimizedQuickSort(A, low, pivot - 1);
                low = pivot + 1;
            } else {
                optimizedQuickSort(A, pivot + 1, high);
                high = pivot - 1;
            }
        }
    }
}


/* code from https://www.techiedelight.com/hybrid-quicksort/ */
void printOQarray(int a[], int size){
       
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}
