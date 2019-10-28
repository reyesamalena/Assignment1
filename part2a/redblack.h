#ifndef _redblack_H
#define _redblack_H
#include <iostream>

// header for RedBlack Tree
enum COLOR { RED, BLACK };

class RBNode {
public:
  	int val;
  	COLOR color;
  	RBNode *left, *right, *parent;

  	RBNode(int val) : val(val) {
    		parent = left = right = NULL; 
  
  	 	// Node is created during insertion 
    		// Node is red at insertion 
    		color = RED; 
  	}; 
  	// returns pointer to uncle 
  	RBNode *uncle() {  
		// If no parent or grandparent, then no uncle 
        	if (parent == NULL or parent->parent == NULL)
        		return NULL;

        	if (parent->isOnLeft())
        	// uncle on right 
        		return parent->parent->right;
        	else
        	// uncle on left 
        		return parent->parent->left;
	};
 
	
  	// check if node is left child of parent 
	bool isOnLeft() { return this == parent->left; }

  	// returns pointer to sibling
  	RBNode *sibling() {
		// sibling null if no parent 
        	if (parent == NULL)
        		return NULL;

        	if (isOnLeft())
        		return parent->right;

        	return parent->left;
	};

  	// moves node down and moves given node in its place
  	void moveDown(RBNode *nParent);

  	bool hasRedChild();

};

class RBTree {
public:
	RBNode *root;
	
	// left rotates the given node
	void leftRotate(RBNode *x);

	void rightRotate(RBNode *x);

	void swapColors(RBNode *x1, RBNode *x2);

	void swapValues(RBNode *u, RBNode *v);

	// fix red red at given node
	void fixRedRed(RBNode *x);
	
	// find node that do not have a left child
	// in the subtree of the given node
	RBNode *successor(RBNode *x);

	// find node that replaces a deleted node in BST 
	RBNode *BSTreplace(RBNode *x);

	// deletes the given node 
	void deleteRBNode(RBNode *v);

	void fixDoubleBlack(RBNode *x);

	// prints level order for given node
	void levelOrder(RBNode *x);
	
	// prints inorder recursively
	void inorder(RBNode *x);

	// constructor
	// initialize root
	RBTree() {root = NULL; };

	RBNode *getRoot() { return root; };

	// searches for given value
	// if found returns the node (used for delete)
	// else returns the last node while traversing (used in insert)
	RBNode *search(int n);

	// inserts the given value to tree
	void insert(int n);

	// utility function that deletes the node with given value
	void deleteByVal(int n);

	// prints inorder of the tree
	void printInOrder();

	// prints level order of the tree
	void printLevelOrder();
};

#endif

/* https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/ */
