#include <iostream>
#include <vector>
using namespace std;

// this function will perform binary search
// it'll return the index of the searched value if it exists,
// -1 otherwise
int binary_search_iterative(const vector<int> &v, int num_to_search_for)
{
    if (v.size() == 0)
        return -1;

    int lo = 0;
    int hi = v.size() - 1;

    // if lo and hi ever cross each other, that means the value
    // wasn't in the array
    while (lo <= hi)
    {
        // guess in the middle
        int guess = (lo + hi) / 2;
        // update lo/hi based on our guess if we didn't find it in the middle
        // if we did find it, return the index
        if (v[guess] < num_to_search_for)
        {
            // this means that we need to look from [guess+1, hi]
            lo = guess + 1;
        }
        else if (v[guess] > num_to_search_for)
        {
            // this means that we need to look from [lo, guess-1]
            hi = guess - 1;
        }
        else
        {
            // we found it!
            return guess;
        }
    }

    // it wasn't there
    return -1;
}

int binary_search_recursive_helper(const vector<int> &v,
                                   int num_to_search_for,
                                   int lo,
                                   int hi)
{
    if (lo > hi) {
        // base case: lo has passed hi
        return -1;
    }

    // recursive case:
    // guess in the middle
    int guess = (lo + hi) / 2;
    // update lo/hi based on our guess if we didn't find it in the middle
    // if we did find it, return the index
    if (v[guess] < num_to_search_for) {
        // this means that we need to look from [guess+1, hi]
        return binary_search_recursive_helper(v, num_to_search_for, guess + 1, hi);
    } else if (v[guess] > num_to_search_for) {
        // this means that we need to look from [lo, guess-1]
        hi = guess - 1;
        return binary_search_recursive_helper(v, num_to_search_for, lo, guess - 1);
    } else {
        // we found it!
        return guess;
    }
}

int binary_search_recursive(const vector<int> &v, int num_to_search_for)
{
    if (v.size() == 0)
        return -1;
    return binary_search_recursive_helper(v, num_to_search_for, 0, v.size() - 1);
}

int main()
{
    vector<int> a = {6, 13, 14, 25, 33, 43, 51, 53, 64, 72, 84, 93, 95, 96, 97};

    cout << "Searching for " << 33 << ": " << binary_search_iterative(a, 33) << endl;
    cout << "Searching for " << 34 << ": " << binary_search_iterative(a, 34) << endl;
    cout << "Searching for " << 6 << ": " << binary_search_iterative(a, 6) << endl;
    cout << "Searching for " << 5 << ": " << binary_search_iterative(a, 5) << endl;
    cout << "Searching for " << 97 << ": " << binary_search_iterative(a, 97) << endl;
    cout << "Searching for " << 98 << ": " << binary_search_iterative(a, 98) << endl;

    cout << "Searching for " << 33 << ": " << binary_search_recursive(a, 33) << endl;
    cout << "Searching for " << 34 << ": " << binary_search_recursive(a, 34) << endl;
    cout << "Searching for " << 6 << ": " << binary_search_recursive(a, 6) << endl;
    cout << "Searching for " << 5 << ": " << binary_search_recursive(a, 5) << endl;
    cout << "Searching for " << 97 << ": " << binary_search_recursive(a, 97) << endl;
    cout << "Searching for " << 98 << ": " << binary_search_recursive(a, 98) << endl;

    return 0;
}