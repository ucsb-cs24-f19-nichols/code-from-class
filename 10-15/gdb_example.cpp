// compile with debug symbols turned on! (-g)
// g++ -g -std=c++11 gdb_example.cpp -o gdb_example
// gdb gdbexample
// ^ On Macs, you have lldb instead. It's really similar,
//   but it doesn't work exactly the same.

#include <iostream>
#include <cstdlib>
using namespace std;

void foo() {
    cout << "foo()" << endl;
}

void segfault3() {
    int x = 3;
    int *p = nullptr;
    cout << *p << endl; // segfault will happen right here!
}

void segfault2() {
    int w = 2;
    segfault3();
}

void elaborate_segfault() {
    int v = 1;
    segfault2();
}

int main(int argc, char *argv[])
{
    int arg = atoi(argv[1]); // this takes in one command-line arguments
    cout << "You entered " << arg << " as a command line argument.\n";

    int x = 5;
    x = x + 1;
    x = x + 2;

    foo();

    elaborate_segfault();

    return 0;
}
