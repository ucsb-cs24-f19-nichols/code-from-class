#include <iostream>
using namespace std;
#include "max.h"

int main(int argc, char const *argv[])
{
    // we'll try to call maximum1<int>,
    // but we don't have the actual code to specialize
    // Therefore we'll get a linker error
    // because we'll never generate maximum1<int>.
    cout << maximum1(42, 43) << endl;

    return 0;
}
