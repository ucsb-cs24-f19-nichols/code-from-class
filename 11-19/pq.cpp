#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int> pq; // this is a heap!
    // things will be extracted in sorted order, from 
    // max to min
    // The top of the priority_queue (i.e., heap) is the current
    // max element stored inside.
    pq.push(10);
    pq.push(2);
    pq.push(80);
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
    pq.pop();

    return 0;
}
