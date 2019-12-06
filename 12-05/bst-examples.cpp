#include <iostream>
using namespace std;

class BST {
public:
    BST() : root(0) {} // start out the root at null

    // copy constructor
    BST(const BST &other);

    // destructor
    ~BST();

    // we don't want duplicates in the tree! We'll return
    // false if the item already exists; true otherwise.
    bool insert(int item);

private:
    class BSTNode {
    public:
        BSTNode* left;
        BSTNode* right;
        BSTNode* parent;
        const int data;
        BSTNode( const int &d ) : data(d) {
            left = right = parent = 0;
        }
    };

    BSTNode *root;
};

// copy constructor
BST::BST(const BST &other) {

}

// destructor
BST::~BST() {
    
}

bool BST::insert(int item) {
    BSTNode *new_node = new BSTNode(item);

    // if we have an empty tree, we need to make this new Node the root
    if (root == nullptr) {
        root = new_node;
        return true; // we definitely made a new Node
    }

    // this is the non-empty BST case
    // pretend that we're searching for the node now
    // (starting at the root)
    BSTNode *n = root;
    while (true) {
        // figure out if we need to search left or right
        // we already had the node in the tree
        if (n->data == item) { return false; }
        else if (item < n->data) {
            // let's go left from here
            if (n->left == nullptr) {
                // we need to put the new Node here
                n->left = new_node;
                new_node->parent = n;
                return true;
            } else {
                // keep on travering the tree
                n = n->left;
            }
        } else { // item > n->data
            // let's go right from here
            if (n->right == nullptr) {
                // we need to put the new Node here
                n->right = new_node;
                new_node->parent = n;
                return true;
            } else {
                // keep on travering the tree
                n = n->right;
            }
        }
    }
}

int main() {

    return 0;
}