#include "quicksort.h"
#include <iostream>
#include "radixsort.h"
#include "timsort.h"
#include <chrono>
#include <algorithm>


using namespace std::chrono;

using namespace std;

int main()  
{
    
    //quick sort
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);
    auto quick_start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto quick_stop = high_resolution_clock::now();
    auto quick_duration = duration_cast<microseconds>(quick_stop - quick_start);
    cout << "Quicksort Sorted Array: \n";
    printArray(arr, n);
    cout << "Time: " << quick_duration.count() << " microsecond " << endl;
    
    //radix sort
    int Radixarr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int Rn = sizeof(Radixarr)/sizeof(Radixarr[0]);
    cout << "Radixsort Sorted Array: \n";
    auto radix_start = high_resolution_clock::now();
    radixsort(Radixarr, Rn);
    auto radix_stop = high_resolution_clock::now();
    print(Radixarr, Rn);
    auto radix_duration = duration_cast<microseconds>(radix_stop - radix_start);
    cout << "Time: " << radix_duration.count() << " microsecond " << endl;
    
    //timsort
      int Timarr[] = {5, 21, 7, 23, 19};
      int Tn = sizeof(Timarr)/sizeof(Timarr[0]);
    
      auto tim_start = high_resolution_clock::now();
      timSort(Timarr, Tn);
      auto tim_stop = high_resolution_clock::now();
    
      auto tim_duration = duration_cast<microseconds>(tim_stop - tim_start);
      printf("Tim Sorted Array: \n");
      print_TArray(Timarr, Tn);
      cout << "Time: " << tim_duration.count() << " microsecond " << endl;
    
    return 0;  
}  
