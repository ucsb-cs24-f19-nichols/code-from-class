#include <iostream>
#include <queue>
using namespace std;

// another word for a class that overloads the function call
// operator is a "functor"
class cmp {
public:
    bool operator() (const int &x, const int &y) {
        return x > y;
    }
};

void printElements(int arr[], int size) {
    int *p = arr; // arr is the beginning
    int *end = arr + size; // one past the last element of the array
   
    while (p != end) {
        cout << *p << endl;
        ++p;
    }
}

int main() {
    cmp compare;

    // this comparison class overloads the function call operator
    // this means that I can call an object of this class like a function!
    cout << compare(4,5) << endl;
    cout << compare(5,4) << endl;

    return 0;
}