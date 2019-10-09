#include <iostream> // cout
using namespace std;

int main() {
    int x = 5;
    int *p; // p is a pointer to an integer
    // p holds ADDRESSES of integer variables
    int **q; // q is a pointer to pointers to ints

    p = &x; // p holds the address of x now
    q = &p; // q holds the address of p now

    x = 6;
    *p = 7; // equivalent to x = 7;
    **q = 8; // equivalent to x = 8; OR *p = 8;

    cout << x << endl;
    cout << *p << endl;
    cout << **q << endl;

    // these are just addresses; they're essentially random
    cout << p << endl;
    cout << q << endl;

    p = NULL; // a pointer can hold the special address NULL/nullptr/0
    // and you never have access to the NULL address!
    // (so don't dereference a pointer set to NULL)

    return 0;
}