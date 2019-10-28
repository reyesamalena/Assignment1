#include <iostream>
#include <chrono>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include "avl.h"
#include "redblack.h"

//million
#define M 1000000
#define D 100000

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
	int AVL_add_height[10];
	int RBT_add[10];
	int RBT_add_height[10];
	int AVL_delete[10];
	int AVL_delete_height[10];
	int RBT_delete[10];
	int RBT_delete_height[10];

	long long int million_start = 0;
	int test_array[M] = {0}; // Sets where the numbers for tree are stored


	for( int j=0; j <10; j++) {
		
		// Create new root for AVL Tree
		Node *AVLroot = NULL;

		//Create new Red-Black Tree
		RBTree rbtree;


		int trial_num = j+1; //keep track of trial number w/o messing with counter
		cout << "Trial " << trial_num << ": " << endl;

		for(unsigned long long int k = million_start; k < (million_start+M); k++) {
			test_array[k-million_start] = k;
		}
		random_shuffle(std::begin(test_array), std::end(test_array)); //randomly shuffling the array

		//Insert into AVL Tree
		auto avl_add_start = high_resolution_clock::now();
		for(unsigned long long int a=0; a<M; a++) {
			AVLroot = insert(AVLroot, test_array[a]);
		}
		auto avl_add_stop = high_resolution_clock::now();
		auto avl_add_duration = duration_cast<microseconds>(avl_add_stop - avl_add_start);
		
		//Insert into Red-Black Tree
		auto rbt_add_start = high_resolution_clock::now();
		for(unsigned long long int a=0; a<M; a++) {
			rbtree.insert(test_array[a]);
		}
		auto rbt_add_stop = high_resolution_clock::now();
		auto rbt_add_duration = duration_cast<microseconds>(rbt_add_stop - rbt_add_start);
		
		cout << "AVL Tree Insert: \n";
		cout << "Time: " << avl_add_duration.count() << " microsecond " << endl;
		cout << endl;
		AVL_add[j] = avl_add_duration.count();
		AVL_add_height[j] = height(AVLroot);
		

		cout << "Red-Black Tree Insert: \n";
		cout << "Time: " << rbt_add_duration.count() << " microsecond " << endl;
		cout << endl;
		RBT_add[j] = rbt_add_duration.count();
		RBT_add_height[j] = maxDepth(rbtree.root);


		//Delete from AVL Tree
		auto avl_del_start = high_resolution_clock::now();
		for(unsigned long long int a=0; a<D; a++) {
			unsigned long long int b = (rand() % M);	
			AVLroot = deleteNode(AVLroot, test_array[b]);
		}
		auto avl_del_stop = high_resolution_clock::now();
		auto avl_del_duration = duration_cast<microseconds>(avl_del_stop - avl_del_start);
	
		
		//Delete from Red-Black Tree	
		auto rbt_del_start = high_resolution_clock::now();
		for( int a=0; a<D; a++) {
			unsigned long long int b = (rand() % M);	
			rbtree.deleteByVal(test_array[b]);
		}
		auto rbt_del_stop = high_resolution_clock::now();
		auto rbt_del_duration = duration_cast<microseconds>(rbt_del_stop - rbt_del_start);
		
		
		cout << "AVL Tree Delete: \n";
		cout << "Time: " << avl_del_duration.count() << " microsecond " << endl;
		cout << endl;
		AVL_delete[j] = avl_del_duration.count();
		AVL_delete_height[j] = height(AVLroot);
		

		cout << "Red-Black Tree Delete: \n";
		cout << "Time: " << rbt_add_duration.count() << " microsecond " << endl;
		cout << endl;
		RBT_delete[j] = rbt_del_duration.count();
		RBT_delete_height[j] = maxDepth(rbtree.root);
		
		million_start = million_start + M;
	}

	
	// Print Tables
	const int nameWidth = 21;
    	const int numWidth = 10;
    	int x;

    	
//Insert Times
	cout << "\t\t\t\tInsert Times" << endl;
	//Print out column names
    	printElement("Trees", nameWidth);
    	for(x=1;x<=10;x++) {
            cout<< "Trial " << x << "   "; }
    	cout << endl;

	//Print 1st row for AVL Tree
	printElement("AVL Tree ", nameWidth);
    	for(x=0;x<10;x++) {
            printElement(AVL_add[x], numWidth); }
    	cout << endl;		
   	
	//Print 2nd row for AVL Tree
	printElement("AVL Height ", nameWidth);
    	for(x=0;x<10;x++) {
            printElement(AVL_add_height[x], numWidth); }
    	cout << endl;		
	
	//Print 3rd row for RB Tree
	printElement("Red-Black Tree", nameWidth);
    	for(x=0;x<10;x++) {
            printElement(RBT_add[x], numWidth); }
    	cout << endl;	
	
	//Print 4th row for RB Tree
	printElement("Red-Black Height", nameWidth);
    	for(x=0;x<10;x++) {
            printElement(RBT_add_height[x], numWidth); }
    	cout << endl << endl;	

//Delete Times
	cout << "\t\t\t\tDelete Times" << endl;
	//Print out column names
    	printElement("Trees", nameWidth);
    	for(x=1;x<=10;x++) {
            cout<< "Trial " << x << "   "; }
    	cout << endl;

	//Print 1st row for AVL Tree
	printElement("AVL Tree", nameWidth);
    	for(x=0;x<10;x++) {
            printElement(AVL_delete[x], numWidth); }
    	cout << endl;	
	
	//Print 2nd row for AVL Tree
	printElement("AVL Height ", nameWidth);
    	for(x=0;x<10;x++) {
            printElement(AVL_delete_height[x], numWidth); }
    	cout << endl;		
	
	//Print 3rd row for RB Tree
	printElement("Red-Black Tree", nameWidth);
    	for(x=0;x<10;x++) {
            printElement(RBT_delete[x], numWidth); }
    	cout << endl;	

	//Print 4th row for RB Tree
	printElement("Red-Black Height", nameWidth);
    	for(x=0;x<10;x++) {
            printElement(RBT_delete_height[x], numWidth); }
    	cout << endl << endl;	


	cout << endl;
	


	return 0;
}
