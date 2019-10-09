#include <iostream> // cout
#include <vector> // for vectors!
using namespace std;

// int arr[10];
// is equivalent to
// vector<int> v;
// v.resize(10);

int main() {
    vector<int> v;
    cout << v.size() << endl;

    for (int i = 1; i <= 10; i++) {
        v.push_back(i); // add i to the end of the vector v
    }

    // print contents
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // C++ 11 range-based for loop
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}