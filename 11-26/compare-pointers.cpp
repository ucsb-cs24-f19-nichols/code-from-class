#include <iostream>
#include <queue>
using namespace std;

// another word for a class that overloads the function call
// operator is a "functor"
class cmpPtr {
public:
    bool operator() (const int *a, const int *b) {
        // we want to compare the values that the pointers store,
        // not the addresses themselves
        return *a > *b; // b has higher priority than a if this returns true
    }
};

int main()
{
    // even though the address of the element 5 has the highest value
    // (as a pointer), it has the lowest value after you follow that pointer
    int arr[] = {10, 9, 8, 7, 6, 5};

    priority_queue<int *, vector<int *>, cmpPtr> pq;
    for (int i = 0; i < 6; i++)
        pq.push(arr + i); // push the addresses of each array element
    while (!pq.empty())
    {
        cout << *pq.top() << endl;
        pq.pop();
    }
    return 0;
}