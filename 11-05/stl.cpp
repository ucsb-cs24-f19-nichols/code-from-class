#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <stack>
using namespace std;

int main() {
    // <???> is template syntax
    array<int, 5> arr = {2, 4, 42, -1, 0};
    vector<int> v;
    list<int> l;
    set<int> bst;

    for (int i = 0; i < arr.size(); i++) {
        v.push_back(arr[i]);
    }
    for (int i : v) {
        l.push_back(i);
    }
    for (auto x : l) {
        // "auto" magically figures out the type for you
        bst.insert(x);
    }

    for (auto x : bst) {
        // iterates through its nodes in-order
        cout << x << " ";
    }
    cout << endl;

    // let's reverse a string using stacks!

    string s = "Hello, world!";
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        st.push(s[i]); // push each character in order
    }
    // popping the stack until it's empty will give me back a reversed string
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    return 0;
}