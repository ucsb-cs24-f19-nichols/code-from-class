#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
T maximum1(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

typedef int item; // if we ever see "item", the compiler replaces it with "int"
item maximum2(item a, item b) {
    if (a > b)
        return a;
    else
        return b;
}


int main(int argc, char const *argv[])
{
    // cout << maximum1<int>(42, 43) << endl;
    // cout << maximum1(42.1, 43.2) << endl; // compiler can figure out the <double>
    // cout << maximum1<string>("foo", "bar") << endl;

    cout << maximum2(42, 43) << endl;
    cout << maximum2(string("foo"), string("bar")) << endl;

    return 0;
}
