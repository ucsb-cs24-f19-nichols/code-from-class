// a .h file is a header file
// it includes declarations, but not implementations

// these fancy things here and the end of the file make
// sure that you can't #include the file more than once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>

class LinkedList
{
public:
    LinkedList();  // constructor
    LinkedList(const LinkedList &other); // copy constructor
    ~LinkedList(); // destructor

    int sum() const; // sum the list, recursively!

    void append(int x); // adds a new Node to the list with info=x
    void print() const; // prints the list
    std::vector<int> vectorize() const; // turns the list into a vector

    friend std::ostream& operator<<(std::ostream &os, const LinkedList &l);

    LinkedList &operator=(const LinkedList &other); // copy assignment

    // A friend function is a non-member function.
    // This declaration says to the compiler that it will eventually find
    // a function of this name (with these argument types), and it also
    // tells it to allow that function to access the private member
    // variables of this class.
    friend bool operator==(const LinkedList &l1, const LinkedList &l2);
    // bool operator==(const LinkedList &other) const; // compare for (value) equality
    bool operator!=(const LinkedList &other) const;
    friend LinkedList operator+(const LinkedList &l1, const LinkedList &l2);
private:
    // definition of Node
    struct Node
    {
        int info;
        Node *next;
    };
    Node *head; // pointer to first node
    Node *tail; // pointer to the last node

    int sum(Node *n) const;
};

bool operator==(const LinkedList &l1, const LinkedList &l2);

// this will return l2 added to the end of l1 in a new list
// e.g., if l1 = [1,2,3], and l2 = [4,5,6], l1 + l2 will return [1,2,3,4,5,6]
LinkedList operator+(const LinkedList &l1, const LinkedList &l2);

#endif