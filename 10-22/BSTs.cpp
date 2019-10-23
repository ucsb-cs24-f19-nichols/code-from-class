#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class BST {
public:
    BST() : root(0) {} // start out the root at null

    // we don't want duplicates in the tree! We'll return
    // false if the item already exists; true otherwise.
    bool insert(int item);
    int max() const;
    int min() const;

    void print_InOrder() const; // calls helper function with the root
    void print_PreOrder() const; // calls helper function with the root
    void print_PostOrder() const; // calls helper function with the root

    friend void test_bst();

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
    void print_InOrder(BSTNode *root) const; // recursive helper function!
    void print_PreOrder(BSTNode *root) const; // recursive helper function!
    void print_PostOrder(BSTNode *root) const; // recursive helper function!
};

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

int BST::max() const {
    // start at the root, and keep going right
    BSTNode *n = root;
    while (n->right != nullptr) {
        n = n->right;
    }
    return n->data;
}

int BST::min() const {
    // start at the root, and keep going left
    BSTNode *n = root;
    while (n->left != nullptr) {
        n = n->left;
    }
    return n->data;
}

void BST::print_InOrder() const {
    print_InOrder(root);
    cout << "\n";
}

// "root" here means the root of the current sub-tree
void BST::print_InOrder(BSTNode *root) const {
    if (root == nullptr) { return; } // nothing to do for an empty tree

    // visit left subtree
    print_InOrder(root->left);

    // print our root
    cout << root->data << " ";

    // visit right subtree
    print_InOrder(root->right);
}

void BST::print_PreOrder() const {
    print_PreOrder(root);
    cout << "\n";
}

// "root" here means the root of the current sub-tree
void BST::print_PreOrder(BSTNode *root) const {
    if (root == nullptr) { return; } // nothing to do for an empty tree

    // print our root
    cout << root->data << " ";

    // visit left subtree
    print_PreOrder(root->left);

    // visit right subtree
    print_PreOrder(root->right);
}

void BST::print_PostOrder() const {
    print_PostOrder(root);
    cout << "\n";
}

// "root" here means the root of the current sub-tree
void BST::print_PostOrder(BSTNode *root) const {
    if (root == nullptr) { return; } // nothing to do for an empty tree

    // visit left subtree
    print_PostOrder(root->left);

    // visit right subtree
    print_PostOrder(root->right);

    // print our root
    cout << root->data << " ";
}

void assertTrue(bool b, string test_name) {
    if (!b) {
        cerr << "Assertion Failed: " << test_name << endl;
        exit(1); // ends the program; this function won't even return at this point
    } else {
        cout << "Test Passed!: " << test_name << endl;
    }
}

void test_bst() {
    BST bst;

    bst.insert(42);
    bst.insert(32);
    bst.insert(45);
    bst.insert(12);
    bst.insert(41);
    bst.insert(50);

    assertTrue(bst.root->data == 42, "root's data = 42");
    assertTrue(bst.root->left->data == 32, "root's->left's data = 32");
    assertTrue(bst.root->right->data == 45, "root's->right's data = 45");
    assertTrue(bst.root->left->parent->data == 42, "root's->left's->parent's data = 42");
    assertTrue(bst.root->right->parent->data == 42, "root's->left's->parent's data = 42");

    assertTrue(bst.max() == 50, "max value should be = 50");
    assertTrue(bst.min() == 12, "min value should be = 12");

    bst.print_InOrder();
    bst.print_PreOrder();
    bst.print_PostOrder();
}

int main(int argc, char *argv[])
{
    test_bst();


    return 0;
}
