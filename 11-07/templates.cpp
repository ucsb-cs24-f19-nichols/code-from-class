#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
T maximum(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <class Data>
class BSTNode
{
public:
    BSTNode<Data> *left;
    BSTNode<Data> *right;
    BSTNode<Data> *parent;
    Data const data;
    BSTNode(const Data &d) : data(d)
    {
        left = right = parent = nullptr;
    }
};

int main(int argc, char const *argv[])
{
    cout << maximum<int>(42, 43) << endl;
    cout << maximum(42.1, 43.2) << endl; // compiler can figure out the <double>
    cout << maximum<string>("foo", "bar") << endl;

    //  BSTNode n1(10); // requires int
    BSTNode<int> n2(10);

    // BSTNode* nodePtr;
    BSTNode<int>* nodePtr = new BSTNode<int>(42);

    return 0;
}
