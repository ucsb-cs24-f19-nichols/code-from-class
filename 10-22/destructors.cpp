#include <iostream>
using namespace std;

class A {
public:
    A(int i): i(i) {}
    ~A() { cout << "A's destructor was called! i = " << i << endl;}
private:
    int i;
};

void foo() {
    cout << "inside foo()\n";
    A localA(1);
    A localA2(2);
    cout << "foo() is about to return\n";

    // the destructor of both of these As should run here!
}

A* bar() {
    cout << "inside bar()\n";
    A *a_ptr = new A(3);
    cout << "bar() is about to return\n";
    return a_ptr;
}

int main(int argc, char *argv[])
{
    foo();

    A* a_ptr = bar();

    cout << "about to call delete on a_ptr\n";
    delete a_ptr;
    // we should see this last A's destructor call here!

    return 0;
}
