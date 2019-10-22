#include "timsort.h"
using namespace std; 

  
// this function sorts array from left index to 
// to right index which is of size atmost RUN 
void tinsertionSort(int arr[], int left, int right)
{

    for (int i = left + 1; i <= right; i++)
    { 
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left) 
        { 
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = temp; 
    } 
} 
  
// merge function merges the sorted runs 
void tmerge(int arr[], int l, int m, int r)
{
 
    // original array is broken in two parts 
    // left and right array 
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++) {

        left[i] = arr[l + i];
    }
                        cout <<" A" << endl;
    for (int i = 0; i < len2; i++) {

        right[i] = arr[m + 1 + i]; 
    }
                        cout <<" B" << endl;
    int i = 0;
    int j = 0;
    int k = l;
  
    // after comparing, we merge those two array 
    // in larger sub array 
    while (i < len1 && j < len2) 
    {

        if (left[i] <= right[j]) 
        { 
            arr[k] = left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
          cout <<" C" << endl;
    // copy remaining elements of left, if any 
    while (i < len1) 
    { 
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 
          cout <<" D" << endl;
    // copy remaining element of right, if any 
    while (j < len2) 
    { 
        arr[k] = right[j]; 
        k++; 
        j++; 
    }
            cout <<" E" << endl;
} 
  
// iterative Timsort function to sort the 
// array[0...n-1] (similar to merge sort) 
void timSort(int arr[], int n)
{
    // Sort individual subarrays of size RUN 
    for (int i = 0; i < n; i+=RUN)
        tinsertionSort(arr, i, min((i+31), (n-1)));
  
    // start merging from size RUN (or 32). It will merge 
    // to form size 64, then 128, 256 and so on .... 
    for (int size = RUN; size < n; size = 2*size)
    { 
        // pick starting point of left sub array. We 
        // are going to merge arr[left..left+size-1] 
        // and arr[left+size, left+2*size-1] 
        // After every merge, we increase left by 2*size 
        for (int left = 0; left < n; left += 2*size)
        { 
            // find ending point of left sub array 
            // mid+1 is starting point of right sub array 
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));
   cout <<" 2aaE" << endl;
            // merge sub array arr[left.....mid] & 
            // arr[mid+1....right] 
            tmerge(arr, left, mid, right);
            cout <<" 1E" << endl;
        }
       
    } 
} 

// utility function to print the Array
void print_TArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}
/* code from https://www.geeksforgeeks.org/timsort/ */
