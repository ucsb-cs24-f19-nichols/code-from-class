#include <iostream>
using namespace std;

// represents numbers of the form ax^2 + bx + c
class Quadratic {
public:
    /*
    This initializes the member variables using assignment statements.
    But we like initialization lists better!
    Quadratic(double aVal = 0, double bVal = 0, double cVal = 0) {
        
        a = aVal;
        b = bVal;
        c = cVal;
    }
    */

   // This is the same thing as above, but using initialization lists this time!
   Quadratic(double aVal = 0, double bVal = 0, double cVal = 0) : 
    a(aVal), b(bVal), c(cVal), y(5) {}

    // the destructor is usually the place where you deallocate
    // any heap memory associated with your object
    ~Quadratic() {
       cout << "Quadratic destructor called!" << endl;
    }

    // copy constructor
    // const because we don't want to change the other thing
    // (we just want to use its values)
    // & (reference) because we want to be efficient
    // references make it so that nothing gets copied
    Quadratic(const Quadratic &other) : 
      a(other.a), b(other.b), c(other.c), y(other.y) 
    {
        cout << "Copy constructor called!\n";
    }

    // the reason you return yourself is due to the same idea as
    // the following:
    // int x, y, z;
    // x = (y = (z = 5));

    // cout << x << ' ' << y << '\n';
    // calls cout.operator<< -- the reason this can take multiple <<
    // cout.operator<<(x).operator<<(' ')...
    // is because ^ this returns cout

    // copy assignment
    // has to return a reference to the class's type
    // (i.e., the current object that you're updating)
    Quadratic& operator= (const Quadratic &other) {
        cout << "Copy assignment operator called!\n";
        a = other.a;
        b = other.b;
        c = other.c;

        // return ourselves
        // the keyword "this" is a pointer to ourselves
        return *this; // this returns not a Quadratic *, but a Quadratic (which gets converted into a reference)
    }

    /*Quadratic operator+(const Quadratic &q2) {
        Quadratic ret(a + q2.a, b + q2.b, c + q2.c);
        return ret;
    }*/

    double evaluate(double x) const {
        return a*x*x + b*x + c;
    }

    double geta() const { return a; }
    double getb() const { return b; }
    double getc() const { return c; }

    // friend Quadratic operator+(const Quadratic &q1, const Quadratic &q2);
private:
    double a;
    double b;
    double c;

    const int y; // you can have a constant member variable that holds 
                 // a different value in each object. We need to be able
                 // to initialize this in the constructor.
};

// this function needs to be a "friend" of the Quadratic class
// in order to access its private member variables
/*Quadratic operator+(const Quadratic &q1, const Quadratic &q2) {
   Quadratic ret(q1.a + q2.a, q1.b + q2.b, q1.c + q2.c);
   return ret;
}*/

Quadratic operator+(const Quadratic &q1, const Quadratic &q2) {
   Quadratic ret(q1.geta() + q2.geta(), q1.getb() + q2.getb(), q1.getc() + q2.getc());
   return ret;
}

void foo() {
    Quadratic p;
    Quadratic *q = new Quadratic;
    delete q;
}

void foo2() {
    // Quadratic p1; Quadratic p2(1, 2, 3);
    
    // Quadratic p1(1, 2, 3); Quadratic p2(p1);
    
    Quadratic *p1 = new Quadratic(1, 2, 3);
    Quadratic p2 = *p1;
}

int main() {
    
    // make a quadratic equation with a = 1, b = 2, and c = 3
    Quadratic q(1, 2, 3);
    cout << q.evaluate(5) << endl; // this prints out 1*5^2 + 2*5 + 3
    Quadratic q2(q); // calls the copy constructor. q2 is a Quadratic with
                     // the "same stuff" as q
    Quadratic q3 = q2; // also calls the copy constructor
    Quadratic q4;
    q4 = q3; // calls the copy assignment operator
    // q4.operator=(q3) is really being called

    cout << (q4+q3).evaluate(5) << endl;
    // calling q4.operator+(q3);
    
    // when you pass along Quadratics by value, the copy constructor gets called!

    // foo();

    // foo2();
}