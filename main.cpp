#include "quicksort.h"
#include <iostream>
#include "radixsort.h"
#include "optquicksort.h"
#include "timsort.h"
#include <chrono>
#include <algorithm>
#include <stdio.h>
#include <iomanip>


//1% of a million
#define N 10000
//million
#define M 1000000
   

//Create template to space out table elements
const char separator = ' ';
template<typename T> void printElement(T t, const int& width) {
	cout << left << setw(width) << setfill(separator) << t; }

using namespace std::chrono;

using namespace std;

int main()  
{
    
    //GENERATING ARRAY
    long long int twentydigit_start = 10000000000000000000;
    long long int million_start = 1;
    long long int one_percent_start = 0;
    int array_one[M] = {0};//Sets where no numbers repeat
    int array_two[N] = {0};//Sets where the range of numbers is 1% of the array size
    int array_three[N] = {0};//Sets where no numbers repeat and each integer has 20 digits
    int randomposition;
    
    //Arrays to keep test results
    int quick_Sort[10];
    int opt_Quick_Sort[10];
    int radix_Sort[10];
    int tim_Sort[10];
    
    for( int j= 0; j<10; j++){
        
	int trial_num = j+1;	//keep track of trial number w/o messing with counter

        cout << "\033[1;31m";       //printing color
        cout  << "Trial " << trial_num <<": "<< endl;       //trial number
        cout << "\033[0m";
        
        for(int k = 0; k < (million_start+M); k++){ //for array one
            array_one[k-million_start] = k;
            
        }
        
        random_shuffle(std::begin(array_one), std::end(array_one)); //randomly shuffling the array one

        
        for( unsigned long long int n = one_percent_start; n< (one_percent_start+N); n++){ //for array two
            array_two[n-one_percent_start] = n;
            array_two[ (n-one_percent_start) +1] = n;
            n++;

        }
        random_shuffle(std::begin(array_two), std::end(array_two)); //randomly shuffling the array

        for( unsigned long long int i = twentydigit_start; i< twentydigit_start+N; i++){ //for array three
        
            array_three[i-twentydigit_start] = i;
        }
        random_shuffle(array_three, array_three +N); //randomly shuffling the array
        
	//QUICK SORT
     
         auto quick_start = high_resolution_clock::now();
         quickSort(array_three, 0, N - 1);
         auto quick_stop = high_resolution_clock::now();
         auto quick_duration = duration_cast<microseconds>(quick_stop - quick_start);
         
         cout << "Quicksort Sorted Array: \n";
         //printArray(arr, n);
         cout << "Time: " << quick_duration.count() << " microsecond " << endl;
         cout << endl;
        quick_Sort[j]=quick_duration.count();
         
    //OPTIMIZED QUICK SORT

         auto o_quick_start = high_resolution_clock::now();
         optimizedQuickSort(array_three, 0, N-1);
         auto o_quick_stop = high_resolution_clock::now();
         auto o_quick_duration = duration_cast<microseconds>(o_quick_stop - o_quick_start);
        
         printf("Optimized Quick Sorted Array: \n");
         //printOQarray(OQuickarr, oqn);
         cout << "Time: " << o_quick_duration.count() << " microsecond " << endl;
         cout << endl;
         opt_Quick_Sort[j]= o_quick_duration.count();

    //RADIX SORT

         
         auto radix_start = high_resolution_clock::now();
         radixsort(array_three, N);
         auto radix_stop = high_resolution_clock::now();
         auto radix_duration = duration_cast<microseconds>(radix_stop - radix_start);
         
         cout << "Radixsort Sorted Array: \n";
         //print(Radixarr, Rn);
         cout << "Time: " << radix_duration.count() << " microsecond " << endl;
         cout << endl;
         radix_Sort[j] = radix_duration.count();

    //TIM SORT
    /*     int Timarr[] = {5, 21, 7, 23, 19};
         int Tn = sizeof(Timarr)/sizeof(Timarr[0]);
         
         auto tim_start = high_resolution_clock::now();
         //timSort(array_one, N);
        int r = 0, nn=N;
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
         tim_Sort[j] = tim_duration.count();
        
       */
        million_start = million_start + M;
        one_percent_start = one_percent_start + N;
        twentydigit_start = twentydigit_start + N;
    }

    //print tables
    const int nameWidth = 21;
    const int numWidth = 10;
    int x;
    
    //Print out column names
    printElement("Algorithms", nameWidth);
    for(x=1;x<=10;x++) {
	    cout<< "Trial " << x << "   "; }
    cout << endl;

    //Print 1st row for QuickSort
    printElement("QuickSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(quick_Sort[x], numWidth); }
    cout << endl;
    
    //Print 2nd row for Optimized QuickSort
    printElement("Optimized QuickSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(opt_Quick_Sort[x], numWidth); }
    cout << endl;

    //Print 3rd row for RadixSort
    printElement("RadixSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(radix_Sort[x], numWidth); }
    cout << endl;
    
    //Print 4th row for TimSort
    printElement("TimSort", nameWidth);
    for(x=0;x<10;x++) {
	   // printElement(tim_Sort[x], numWidth);
        
    }
    cout << endl;
    
    return 0;  
}  
