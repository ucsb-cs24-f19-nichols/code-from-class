#include <iostream>
using namespace std;

class DayOfYear {
 public:
      // DayOfYear();
      DayOfYear(int mon = 1, int day = 1); // default parameters
      void setDate(int mon, int day);
      // the function is const now; it can't change any member variables
      int getMonth() const; 
      int getDay() const;
  private:
      int dd;
int mm;
};

/* DayOfYear::DayOfYear() {
    mm = 1;
    dd = 1;
} */

DayOfYear::DayOfYear(int mon, int day) {
    cout << "Calling the constructor with mon = " << mon <<
         " and day = " << day << "!\n";
    mm = mon;
    dd = day; 
}

void DayOfYear::setDate(int mon, int day) {
    mm = mon;
    dd = day; 
}
int DayOfYear::getMonth() const {
    // this isn't allowed! you can't set member variables when
    // the function is declared as const
    // dd = 1
    return mm; 
}
int DayOfYear::getDay() const {
    // mm = 12;
    return dd; 
}

int main() {
    DayOfYear today; // calls the constructor without parameters
    DayOfYear today2(10, 1); // call the constructor to set mm and dd
    DayOfYear today3(10); // call the constructor to set mm

    // today.setDate(1, 9);
    cout<< "Today’s date is: ";
    cout<< today.getMonth() << "/"
        << today.getDay() << endl;

    int i = 5;
    int j(5); // sets j to 5 
    // ^ constructor syntax

    /*
    // you have to initialize a const variable
    const double PI = 3.14159265;
    PI = 4; // you can't reset a const variable
    */
    
    return 0;
}