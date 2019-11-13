#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

template <class T>
class Stack {
public:
    typedef Stack<T>* StackPtr;

    // we don't need to make an overloaded constructor, because
    // the default constructor will call the constructor for the vector v
    // and start it off empty
    void push(T x) { v.push_back(x); }
    void pop() { v.pop_back(); }
    T top() const { 
        // return what's at the end
        return v[v.size() - 1];
    }

    bool empty() const {
        return v.empty();
    }
    T min() const {
        T min = v[0];
        for (T i = 1; i < v.size(); i++) {
            if (v[i] < min) {
                min = v[i];
            }
        }
        return min;
    }

    StackPtr return_current_stack();

private:
    vector<T> v;
};

// the compiler isn't smart enough to know that
// "Stack<T>::StackPtr" is a type
// you have to tell it so with "typename"
template <class T>
typename Stack<T>::StackPtr Stack<T>::return_current_stack() {
        return this;
}

void my_assert(bool b, string description) {
    if (!b) {
        cerr << "Test failed: " << description << endl;
        exit(1);
    } else {
        cout << "Test passed: " << description << endl;
    }
}

void test_ints() {
    Stack<int> s; // starts out empty
    s.push(1);
    s.push(2);
    s.push(3);

    my_assert(s.top() == 3, "s.top() == 3");
    s.pop();
    my_assert(s.top() == 2, "s.top() == 2");
    s.pop();
    my_assert(s.top() == 1, "s.top() == 1");
    s.pop();
    my_assert(s.empty(), "s.empty()");
}

void test_strings() {
    Stack<string> s; // starts out empty
    s.push("a");
    s.push("b");
    s.push("c");

    my_assert(s.top() == "c", "s.top() == c");
    s.pop();
    my_assert(s.top() == "b", "s.top() == b");
    s.pop();
    my_assert(s.top() == "a", "s.top() == a");
    s.pop();
    my_assert(s.empty(), "s.empty()");
}

int main(int argc, char *argv[])
{
    test_ints();
    test_strings();

    // because StackPtr is an alias for Stack<int>*
    Stack<int>::StackPtr s = new Stack<int>;

    return 0;
}
