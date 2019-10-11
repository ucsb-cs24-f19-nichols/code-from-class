#include <iostream>
using namespace std;

void leak() {
    int *p;
    for (int i = 0; i < 10; i++) {
        p = new int;
    }
}

void segfault() {
    // int *p = nullptr;
    // cout << *p << endl;

    int arr[5];
    cout << arr[5] << endl; // you'll usually have access to this, but
    // it's still "undefined behavior"--you should never do this
    cout << arr[50000] << endl;
}

int main(int argc, char const *argv[])
{
    // leak();   

    // segfault();

    int *p = new int;
    delete p;
    delete p; // you can't free the same memory twice!

    return 0;
}
