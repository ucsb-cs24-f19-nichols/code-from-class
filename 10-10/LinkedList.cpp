// implementation file!

// single quotes because this is in the current directory
// (i.e., LinkedList.h is not a standard library)
#include "LinkedList.h"
#include <iostream>
#include <vector>
using namespace std;

// an empty linked list has NULL head and tail pointers!
// let's set that up properly!
LinkedList::LinkedList() : head(nullptr), tail(0) {}

LinkedList::LinkedList(const LinkedList &other) : 
head(other.head), tail(other.tail) {
    // default behavior is the above

    // this isn't good! We should copy any of the elements
    // so that if we delete on in our linked list, it doesn't affect
    // the linked list that we copied from!

    // Correct solution:
    // iterate through the linked list you want to copy.
    // append each value you see to the list you're building
    // in this constructor.
}

LinkedList::~LinkedList() {
    // default behavior is empty
    // the default destructor calls the destructors for all member variables
    // (and if you override it, it also does this in addition to the body's code)

    // the default destructor doesn't delete any Nodes!

    // Correct solution:
    // you should iterate through the list and delete all the nodes
}

LinkedList& LinkedList::operator=(const LinkedList &other) {
    // default behavior is this:
    head = other.head;
    tail = other.tail;

    return *this;

    // this isn't good! We should copy any of the elements
    // so that if we delete on in our linked list, it doesn't affect
    // the linked list that we copied from!

    // Correct solution:
    // Delete all our current nodes first!
    // Iterate through the linked list you want to assign.
    // Append each value you see to ourselves.
}


void LinkedList::append(int x) {
    // make a new Node (on the heap!)
    Node *n = new Node;
    n->info = x;
    n->next = nullptr;

    // add it to the end of the current linked list
    if (head == nullptr && tail == nullptr) {
        // empty list! n is the only node.
        head = n;
        tail = n;
    } else {
        // non-empty list; let's add to the last element
        tail->next = n;
        tail = n;
    }
}

bool operator==(const LinkedList &l1, const LinkedList &l2) {
    // iterate through both lists at the same time,
    // and see if the values inside each node lines up
    LinkedList::Node *n1 = l1.head; // our head
    LinkedList::Node *n2 = l2.head; // their head

    while (n1 != nullptr && n2 != nullptr) {
        // check if their data values are the same
        if (n1->info != n2->info) return false;

        // keep going; advance both pointers
        n1 = n1->next;
        n2 = n2->next;
    }

    // once we got here, at least one of n1 and n2 is equal to nullptr
    // if they're both nullptr, then the lists were the same
    if (n1 == nullptr && n2 == nullptr) return true;// same length as well as contents
    else return false; // one list wasn't empty (and the other was)
}

// this is a member operator== function
// when you call this, it's like saying l1.operator==(l2);
// It kind of treats l1 as special.
/*bool LinkedList::operator==(const LinkedList &other) const {
    // iterate through both lists at the same time,
    // and see if the values inside each node lines up
    Node *n1 = head; // our head
    Node *n2 = other.head; // their head

    while (n1 != nullptr && n2 != nullptr) {
        // check if their data values are the same
        if (n1->info != n2->info) return false;

        // keep going; advance both pointers
        n1 = n1->next;
        n2 = n2->next;
    }

    // once we got here, at least one of n1 and n2 is equal to nullptr
    // if they're both nullptr, then the lists were the same
    if (n1 == nullptr && n2 == nullptr) return true;// same length as well as contents
    else return false; // one list wasn't empty (and the other was)
}*/

vector<int> LinkedList::vectorize() const {
    vector<int> ret;

    Node *n = head;
    while (n != nullptr) {
        // n->info is shorthand for (*n).info
        ret.push_back(n->info);
        n = n->next;
    }

    return ret;
}

void LinkedList::print() const {
    Node *n = head;
    while (n != nullptr) {
        // n->info is shorthand for (*n).info
        cout << n->info << " ";
        n = n->next;
    }
    cout << endl;
}

bool LinkedList::operator!=(const LinkedList &other) const {
    return !(*this == other);
}

// this function lets us give a linked list to cout!
std::ostream& operator<<(std::ostream &os, const LinkedList &l) {
    LinkedList::Node *n = l.head;
    while (n != nullptr) {
        // n->info is shorthand for (*n).info
        os << n->info << " ";
        n = n->next;
    }
    os << endl;    

    return os;
}