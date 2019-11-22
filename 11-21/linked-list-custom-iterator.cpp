#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int info;
        Node *next;
    };
public:
    LinkedList(): head(0) {}

    void append(int data) {
        Node *new_node = new Node;
        new_node->info = data;
        new_node->next = nullptr;

        if (!head) {
            head = new_node;
            return;
        }

        Node *n = head;
        for (; n->next != nullptr; n = n->next);
        n->next = new_node;
    }

    // TODO: make iterator class, make begin/end functions
    // an iterator of a container class always lives inside the class,
    // and has the name "iterator"
    class iterator {
    public:
        iterator(Node *curr): curr(curr) {} // constructor

        // now we need to overload ++, *, !=
        void operator++() {
            // advance curr to the element
            curr = curr->next;
        }
        int& operator*() const {
            return curr->info;
        }
        bool operator!=(const iterator &other) const {
            return curr != other.curr;
        }
    private:
        Node *curr; // this holds where I currently am in my iteration
    };

    // remember, this function is defined on the LinkedList class
    iterator begin() {
        iterator beg(head);
        return beg;
    }

    iterator end() {
        return iterator(0);
    }

private:
    Node *head;
};

int main(int argc, char *argv[])
{
    LinkedList l;
    l.append(1);
    l.append(2);
    l.append(3);

    // iteration the normal way
    // for (LinkedList::Node *n = l.head; n != 0; n = n->next) {
    //     cout << n->info << endl;
    // }

    // iteration using iterators
    for (LinkedList::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << endl;
    }

    // auto!
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << endl;
    }

    // iteration using the range-based for loop
    // it's doing exactly the above, just with a lot fewer keys to type
    for (int x : l) { // could also use "auto x : l"
        cout << x << endl;
    }

    for (auto it = l.begin(); it != l.end(); ++it) {
        *it = *it + 1;
    }

    for (int x : l) { // could also use "auto x : l"
        cout << x << endl;
    }

    return 0;
}
