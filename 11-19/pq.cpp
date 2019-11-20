#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int> pq;
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
