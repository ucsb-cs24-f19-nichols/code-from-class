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

int main() {
    Complex c; // calls constructor with no parameters; sets everything to 0
    c.print();

    Complex c2(3, 0.14);
    c2.print();
    c2.conj();
    c2.print();
    cout << c2.magnitude() << endl;
}