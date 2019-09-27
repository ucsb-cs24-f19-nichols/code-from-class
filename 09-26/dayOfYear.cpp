// To compile and link:
// g++ dayOfYear.cpp -o dayOfYear
// requires implementations

// To just compile a single file's code into machine code (for later linking):
// g++ -c dayOfYear.cpp
// ^ This will make a dayOfYear.o file that can be linked later

#include <iostream>
using namespace std;

// let's make a class that represents dates in a certain year
// fields: day, month
// methods (a.k.a. the things we want to do to objects of this class):
// setDate(month, day), printDate()
class DayOfYear {
public:
    // sets mm=month and dd=day
    // This is the only way the user gets to set mm and dd
    void setDate(int month, int day) {
        mm = month;
        dd = day;
    }
    void printDate() {
        cout << mm << "/" << dd << endl;
    }
private:
    // a good rule of thumb is to always make member variables private
    int mm;
    int dd;
};

int main() {
    DayOfYear d1;
    d1.setDate(9, 26);
    // d1.mm = 10; // this is outside of the class definition; private variables are hidden
    d1.printDate();

    DayOfYear *d2 = new DayOfYear;
    d2->setDate(9, 27);
    d2->printDate();

    delete d2;

    return 0;
}