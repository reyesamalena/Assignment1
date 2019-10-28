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
