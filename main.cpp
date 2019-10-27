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
    
    //Arrays to keep test results for Array 1
    int quick_Sort1[10];
    int opt_Quick_Sort1[10];
    int radix_Sort1[10];
    int tim_Sort1[10];
    
    //Arrays to keep test results for Array 2
    int quick_Sort2[10];
    int opt_Quick_Sort2[10];
    int radix_Sort2[10];
    int tim_Sort2[10];
   
    //Arrays to keep test results for Array 3
    int quick_Sort3[10];
    int opt_Quick_Sort3[10];
    int radix_Sort3[10];
    int tim_Sort3[10];

    for( int j= 0; j<10; j++){
        
//	int trial_num = j+1;	//keep track of trial number w/o messing with counter

        cout << "\033[1;31m";       //printing color
        cout  << "Trial " << j <<": "<< endl;       //trial number
        cout << "\033[0m";
        
cout << j << endl;
        for(int k = 0; k < (million_start+M); k++){ //for array one
            array_one[k-million_start] = k;
            
        } 
cout << j << endl;
        random_shuffle(std::begin(array_one), std::end(array_one)); //randomly shuffling the array one

        
cout << j << endl;
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
     
	 //Array 1
         auto quick_start1 = high_resolution_clock::now();
         quickSort(array_one, 0, N - 1);
         auto quick_stop1 = high_resolution_clock::now();
         auto quick_duration1 = duration_cast<microseconds>(quick_stop1 - quick_start1);
         
         cout << "Quicksort Sorted Array: \n";
         //printArray(arr, n);
         cout << "Array 1 Time: " << quick_duration1.count() << " microsecond " << endl;
         cout << endl;
         quick_Sort1[j]=quick_duration1.count();
         
	 //Array 2
         auto quick_start2 = high_resolution_clock::now();
         quickSort(array_two, 0, N - 1);
         auto quick_stop2 = high_resolution_clock::now();
         auto quick_duration2 = duration_cast<microseconds>(quick_stop2 - quick_start2);
         
         cout << "Quicksort Sorted Array: \n";
         //printArray(arr, n);
         cout << "Array 2 Time: " << quick_duration2.count() << " microsecond " << endl;
         cout << endl;
         quick_Sort2[j]=quick_duration2.count();

	 //Array 3
         auto quick_start3 = high_resolution_clock::now();
         quickSort(array_three, 0, N - 1);
         auto quick_stop3 = high_resolution_clock::now();
         auto quick_duration3 = duration_cast<microseconds>(quick_stop3 - quick_start3);
         
         cout << "Quicksort Sorted Array: \n";
         //printArray(arr, n);
         cout << "Array 3 Time: " << quick_duration3.count() << " microsecond " << endl;
         cout << endl;
         quick_Sort3[j]=quick_duration3.count();


    //OPTIMIZED QUICK SORT

	 //Array 1
         auto o_quick_start1 = high_resolution_clock::now();
         optimizedQuickSort(array_one, 0, N-1);
         auto o_quick_stop1 = high_resolution_clock::now();
         auto o_quick_duration1 = duration_cast<microseconds>(o_quick_stop1 - o_quick_start1);
        
         printf("Optimized Quick Sorted Array: \n");
         //printOQarray(OQuickarr, oqn);
         cout << "Array 1 Time: " << o_quick_duration1.count() << " microsecond " << endl;
         cout << endl;
         opt_Quick_Sort1[j]= o_quick_duration1.count();

	 //Array 2
         auto o_quick_start2 = high_resolution_clock::now();
         optimizedQuickSort(array_two, 0, N-1);
         auto o_quick_stop2 = high_resolution_clock::now();
         auto o_quick_duration2 = duration_cast<microseconds>(o_quick_stop2 - o_quick_start2);
        
         printf("Optimized Quick Sorted Array: \n");
         //printOQarray(OQuickarr, oqn);
         cout << "Array 2 Time: " << o_quick_duration2.count() << " microsecond " << endl;
         cout << endl;
         opt_Quick_Sort2[j]= o_quick_duration2.count();

	 //Array 3
         auto o_quick_start3 = high_resolution_clock::now();
         optimizedQuickSort(array_three, 0, N-1);
         auto o_quick_stop3 = high_resolution_clock::now();
         auto o_quick_duration3 = duration_cast<microseconds>(o_quick_stop3 - o_quick_start3);
        
         printf("Optimized Quick Sorted Array: \n");
         //printOQarray(OQuickarr, oqn);
         cout << "Array 3 Time: " << o_quick_duration3.count() << " microsecond " << endl;
         cout << endl;
         opt_Quick_Sort3[j]= o_quick_duration3.count();

    //RADIX SORT

         //Array 1 
         auto radix_start1 = high_resolution_clock::now();
         radixsort(array_one, N);
         auto radix_stop1 = high_resolution_clock::now();
         auto radix_duration1 = duration_cast<microseconds>(radix_stop1 - radix_start1);
         
         cout << "Radixsort Sorted Array: \n";
         //print(Radixarr, Rn);
         cout << "Array 1 Time: " << radix_duration1.count() << " microsecond " << endl;
         cout << endl;
         radix_Sort1[j] = radix_duration1.count();

         //Array 2 
         auto radix_start2 = high_resolution_clock::now();
         radixsort(array_two, N);
         auto radix_stop2 = high_resolution_clock::now();
         auto radix_duration2 = duration_cast<microseconds>(radix_stop2 - radix_start2);
         
         cout << "Radixsort Sorted Array: \n";
         //print(Radixarr, Rn);
         cout << "Array 2 Time: " << radix_duration2.count() << " microsecond " << endl;
         cout << endl;
         radix_Sort2[j] = radix_duration2.count();

         //Array 3 
         auto radix_start3 = high_resolution_clock::now();
         radixsort(array_three, N);
         auto radix_stop3 = high_resolution_clock::now();
         auto radix_duration3 = duration_cast<microseconds>(radix_stop3 - radix_start3);
         
         cout << "Radixsort Sorted Array: \n";
         //print(Radixarr, Rn);
         cout << "Array 3 Time: " << radix_duration3.count() << " microsecond " << endl;
         cout << endl;
         radix_Sort3[j] = radix_duration3.count();

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
   

//Array 1
    cout << "\t\t\t\tArray 1" << endl;
    //Print out column names
    printElement("Algorithms", nameWidth);
    for(x=1;x<=10;x++) {
	    cout<< "Trial " << x << "   "; }
    cout << endl;

    //Print 1st row for QuickSort
    printElement("QuickSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(quick_Sort1[x], numWidth); }
    cout << endl;
    
    //Print 2nd row for Optimized QuickSort
    printElement("Optimized QuickSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(opt_Quick_Sort1[x], numWidth); }
    cout << endl;

    //Print 3rd row for RadixSort
    printElement("RadixSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(radix_Sort1[x], numWidth); }
    cout << endl;
    
    //Print 4th row for TimSort
    printElement("TimSort", nameWidth);
    for(x=0;x<10;x++) {
	   // printElement(tim_Sort1[x], numWidth);
        
    }
    cout << endl << endl;
   
//Array 2
    cout << "\t\t\t\tArray 2" << endl;
    //Print out column names
    printElement("Algorithms", nameWidth);
    for(x=1;x<=10;x++) {
	    cout<< "Trial " << x << "   "; }
    cout << endl;

    //Print 1st row for QuickSort
    printElement("QuickSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(quick_Sort2[x], numWidth); }
    cout << endl;
    
    //Print 2nd row for Optimized QuickSort
    printElement("Optimized QuickSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(opt_Quick_Sort2[x], numWidth); }
    cout << endl;

    //Print 3rd row for RadixSort
    printElement("RadixSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(radix_Sort2[x], numWidth); }
    cout << endl;
    
    //Print 4th row for TimSort
    printElement("TimSort", nameWidth);
    for(x=0;x<10;x++) {
	   // printElement(tim_Sort2[x], numWidth);
        
    }
    cout << endl << endl;

//Array 3
    cout << "\t\t\t\tArray 3" << endl;
    //Print out column names
    printElement("Algorithms", nameWidth);
    for(x=1;x<=10;x++) {
	    cout<< "Trial " << x << "   "; }
    cout << endl;

    //Print 1st row for QuickSort
    printElement("QuickSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(quick_Sort3[x], numWidth); }
    cout << endl;
    
    //Print 2nd row for Optimized QuickSort
    printElement("Optimized QuickSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(opt_Quick_Sort3[x], numWidth); }
    cout << endl;

    //Print 3rd row for RadixSort
    printElement("RadixSort", nameWidth);
    for(x=0;x<10;x++) {
	    printElement(radix_Sort3[x], numWidth); }
    cout << endl;
    
    //Print 4th row for TimSort
    printElement("TimSort", nameWidth);
    for(x=0;x<10;x++) {
	   // printElement(tim_Sort3[x], numWidth);
        
    }
    cout << endl;

    return 0;  
}  
