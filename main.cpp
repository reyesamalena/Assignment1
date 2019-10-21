#include "quicksort.h"
#include <iostream>
#include "radixsort.h"

using namespace std;

int main()  
{
    
    //quick sort
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Quicksort Sorted Array: \n";
    printArray(arr, n);
    
    //radix sort
    int Radixarr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int Rn = sizeof(Radixarr)/sizeof(Radixarr[0]);
    cout << "Radixsort Sorted Array: \n"; 
    radixsort(Radixarr, Rn);
    print(Radixarr, Rn);
    
    return 0;  
}  
