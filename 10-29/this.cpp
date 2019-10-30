// the keyword "this" is a pointer to the object
// that the member function was called on

class C {
public:
    // the argument x shadows the private member variable x,
    // but I can still get it by using this
    void setX(int x) { this->x = x; } 
private:
    int x;
};

int main(int argc, char *argv[])
{
    C c;
    c.setX(5);  // inside C::setX, "this" is set to &c

    C c2;
    c2.setX(7); // this is set to &c2

    return 0;
}
