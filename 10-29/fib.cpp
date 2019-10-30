#include <iostream>
using namespace std;

int fib1(int n) {
    if (n == 1 || n == 2) return 1;
    else return fib1(n-1) + fib1(n-2);
}

int fib2(int n) {
    int *arr = new int[n+1];
    arr[1] = arr[2] = 1;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    int answer = arr[n];
    delete[] arr; // we don't like memory leaks

    return answer;
}



int main(int argc, char *argv[])
{
    // cout << fib1(200) << endl;
    cout << fib2(200) << endl;

    return 0;
}
