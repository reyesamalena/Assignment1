#ifndef _avl_H
#define _avl_H
#include <iostream>

using namespace std;
// An AVL tree node  
class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};

// A utility function to get maximum 
// of two integers 
int max(int a,int b);

// A utility function to get height
// of the tree
int height(Node *N);

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
Node* newNode(int key);

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y);

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x);

// Get Balance factor of node N
int getBalance(Node *N);


Node* insert(Node* node, int key);

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
Node * minValueNode(Node* node);

// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
Node* deleteNode(Node* root, int key);

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root);

#endif
