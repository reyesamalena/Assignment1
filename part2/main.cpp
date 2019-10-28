#include <iostream>
#include <chrono>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include "avl.h"
#include "redblack.h"

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
	
	//Arrays to keep test results
	int AVL_add[10];
	int RBT_add[10];
	int AVL_delete[10];
	int RBT_delet[10];

	long long int million_start = 0;
	int test_array[M] = {0}; // Sets where the numbers for tree are stored


	for( int j=0; j <10; j++) {
		
		int trial_num = j+1; //keep track of trial number w/o messing with counter

		cout << "Trial " << trial_num << ": " << endl;

		for(unsigned long long int k = million_start; k < (million_start+M); k++) {
			test_array[k-million_start] = k;
		}
		random_shuffle(std::begin(test_array), std::end(test_array)); //randomly shuffling the array
	}




	return 0;
}
