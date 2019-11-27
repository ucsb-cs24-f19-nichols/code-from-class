#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    clock_t time_before = clock();

    double d = 0;
    for (int i = 0; i < 100000; i++)
    {
        for (int j = 0; j < 1000; j++) {
            d += sqrt(i);
        }
    }
    cout << d << endl;

    clock_t time_after = clock(); // time will have passed, so clock() returns something else

    cout << "This took " << (time_after - time_before) << " 'clocks'.\n";
    cout << "That is  " << (time_after - time_before)/static_cast<double>(CLOCKS_PER_SEC) << " seconds.\n";
    cout << "That is  " << (time_after - time_before)/static_cast<double>(CLOCKS_PER_SEC)*1000 << " milliseconds.\n";

    return 0;
}
