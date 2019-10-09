#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

// this function makes sure something was true; complains if not
void assertTrue(bool b, string testName) {
    if (b) {
        cout << "PASSED: " << testName << "\n";
    } else {
        cout << "FAILED: " << testName << "\n";
    }
}

class LinkedListTest {
public:
    // let's test our operator== function
    void test_operator_eqeq() {
        LinkedList l1;
        LinkedList l2;

        // test case  1 -- empty lists should be equal
        assertTrue(l1 == l2, "empty lists =="); // we're asserting the fact that l1 should be equal to l2

        l1.append(1);

        // test case 2 -- now the lists aren't the same!
        assertTrue(!(l1 == l2), "l1 = [1], l2 = []");

        l2.append(1);

        // test case 3 -- now the lists are the same again
        assertTrue(l1 == l2, "l1 = [1], l2 = [1]");

        // you can add as many test cases as you'd like--enough to convince
        // you that your implementation is correct
    }
};

int main() {
    LinkedListTest tests;

    tests.test_operator_eqeq(); // runs our test for the == operator on LinkedLists

    return 0;
}