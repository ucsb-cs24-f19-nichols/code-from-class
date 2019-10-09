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

    void append(int x); // adds a new Node to the list with info=x
    void print() const; // prints the list
    std::vector<int> vectorize() const; // turns the list into a vector

    LinkedList &operator=(const LinkedList &other); // copy assignment

    bool operator==(const LinkedList &other) const; // compare for (value) equality
    // int size(); // size of the list
private:
    // definition of Node
    struct Node
    {
        int info;
        Node *next;
    };
    Node *head; // pointer to first node
    Node *tail; // pointer to the last node
};

#endif