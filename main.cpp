#include "quicksort.h"
#include <iostream>
#include "radixsort.h"
#include "optquicksort.h"
#include "timsort.h"
#include <chrono>
#include <algorithm>
#include <stdio.h>

//1% of a million
#define N 10000

using namespace std::chrono;

using namespace std;

int main()  
{
    
    //GENERATING ARRAY
    unsigned long long int twentydigit_start = 10000000000000000000;
    int testarray[N] = {0};
    int randomposition;
    
    for( int j= 0; j<10; j++){
        cout << "\033[1;31m";
        cout  << "Trial " << j++ <<": "<< endl;
        cout << "\033[0m";
        
        for( long long int i = twentydigit_start; i< twentydigit_start+N; i++){
        
            testarray[i-twentydigit_start] = i;

        }
        random_shuffle(testarray, testarray +N); //randomly shuffling the array
        //QUICK SORT
         int arr[] = {10, 7, 8, 9, 1, 5};
         int n = sizeof(arr) / sizeof(arr[0]);
         
         auto quick_start = high_resolution_clock::now();
         quickSort(testarray, 0, N - 1);
         auto quick_stop = high_resolution_clock::now();
         auto quick_duration = duration_cast<microseconds>(quick_stop - quick_start);
         
         cout << "Quicksort Sorted Array: \n";
         //printArray(arr, n);
         cout << "Time: " << quick_duration.count() << " microsecond " << endl;
         cout << endl;
         
         //OPTIMIZED QUICK SORT
         int OQuickarr[] = {10, 7, 8, 9, 1, 5};
         int oqn = sizeof(OQuickarr)/sizeof(OQuickarr[0]);
         
         auto o_quick_start = high_resolution_clock::now();
         optimizedQuickSort(testarray, 0, N-1);
         auto o_quick_stop = high_resolution_clock::now();
         auto o_quick_duration = duration_cast<microseconds>(o_quick_stop - o_quick_start);
        
         printf("Optimized quick Sorted Array: \n");
         //printOQarray(OQuickarr, oqn);
         cout << "Time: " << o_quick_duration.count() << " microsecond " << endl;
         cout << endl;
         
         //RADIX SORT
         int Radixarr[] = {170, 45, 75, 90, 802, 24, 2, 66};
         int Rn = sizeof(Radixarr)/sizeof(Radixarr[0]);
         
         auto radix_start = high_resolution_clock::now();
         radixsort(testarray, N);
         auto radix_stop = high_resolution_clock::now();
         auto radix_duration = duration_cast<microseconds>(radix_stop - radix_start);
         
         cout << "Radixsort Sorted Array: \n";
         //print(Radixarr, Rn);
         cout << "Time: " << radix_duration.count() << " microsecond " << endl;
         cout << endl;
         
         //TIM SORT
         int Timarr[] = {5, 21, 7, 23, 19};
         int Tn = sizeof(Timarr)/sizeof(Timarr[0]);
         
         auto tim_start = high_resolution_clock::now();
         //timSort(testarray, N);
        int r = 0, nn=N;           /* станет 1 если среди сдвинутых битов будет хотя бы 1 ненулевой */
         while (nn >= 64) {
             r |= nn & 1;
             nn >>= 1;
         }
         cout<< nn + r<<endl;

         auto tim_stop = high_resolution_clock::now();
         auto tim_duration = duration_cast<microseconds>(tim_stop - tim_start);
         
         printf("Tim Sorted Array: \n");
         //print_TArray(Timarr, Tn);
         cout << "Time: " << tim_duration.count() << " microsecond " << endl;
         cout << endl;
        
        
        
        twentydigit_start = twentydigit_start + N;
    }


    
    
    
    
    return 0;  
}  
