/*

Exceptions indicate some sort of "exceptional" behavior. They
mark any sort of issue that needs to interrupt the normal
control of the program to be handled, but they are not serious
enough to warrant stopping the program completely.

The metaphor is that you "throw" exceptions, and code to handle
them "catches" those exceptions. You can throw lots of different
types (and make up your own!)--in this example I'll throw a
string.

You have to handle the exception by using a try/catch block. If 
your program throws an exception and doesn't catch it, it stops
the program with a runtime error.

*/

#include <iostream>
#include <string>
using namespace std;

int divide(int x, int y) {
    return x / y;
}

int divide_with_exceptions(int x, int y) {
    if (y == 0) {
        // this will invoke the closest exception handler (try/catch)
        // that knows how to deal with strings
        throw string("division by 0");
        // notice that we don't have to return an int here, even though
        // the function expects that. Exceptions stop the normal execution
        // of a program.
    } else {
        return x / y;
    }
}

int main(int argc, char *argv[])
{
    cout << divide(4, 2) << endl;
    // cout << divide(4, 0) << endl; // stops the program

    cout << divide_with_exceptions(4, 2) << endl;
    // cout << divide_with_exceptions(4, 0) << endl; // stops the program in a different way

    try {
        // stuff in here might throw exceptions; go until we throw one
        // (we might not!)
        cout << divide_with_exceptions(4, 0) << endl;
    } catch (string s) {
        // here is how we handle those exceptions
        cout << "error: " << s << endl;
    }

    // as long as you catch the exception, your program is allowed
    // to continue
    cout << divide_with_exceptions(8, 2) << endl;

    return 0;
}
