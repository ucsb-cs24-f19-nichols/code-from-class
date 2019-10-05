#include <iostream>
#include <cmath>
using namespace std;

class Complex {
public:
    Complex(double a = 0, double b = 0);
    void print() const;
    void conj();
    double magnitude() const;
    double getReal() const;
    double getImaginary() const;
private:
    double im;
    double re;
};

Complex::Complex(double a, double b) {
    cout << "Complex Constructor was called!\n";
    im = a;
    re = b;
}

double Complex::getReal() const { return re; }
double Complex::getImaginary() const { return im; }

void Complex::print() const {
    cout << im << "i + " << re << endl;
}

double Complex::magnitude() const {
    return sqrt(im*im + re*re);
}

void Complex::conj() {
    re = -re;
}

void foo(){
    Complex c;
    Complex* c2 = new Complex; // this one goes on the heap!
    Complex c3(10, 5);
}

int main() {
    foo();
    return 0;
}