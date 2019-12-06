#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// let's make a templated, generic function that takes a vector as input
// reverses all elements of that vector using a stack
// and returns a new vector that is the reverse of the input vector

template <class T>
vector<T> reverse(const vector<T> &v) {
    // reverse using a stack
    stack<T> s;

    for (int i = 0; i < v.size(); i++) {
        s.push(v[i]);
    }

    // now we'll pop off the stack and everything will be in reverse order

    vector<T> ret;
    while (!s.empty()) {
        ret.push_back(s.top());
        s.pop();
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');

    vector<char> v_reversed = reverse<char>(v); // could also just say "reverse(v);"

    for (int i = 0; i < v_reversed.size(); i++) {
        cout << v_reversed[i] << " ";
    }
    cout << endl;

    return 0;
}
