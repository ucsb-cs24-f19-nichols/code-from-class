#include <iostream>
#include <vector>
using namespace std;

class IntStack {
public:
    // we don't need to make an overloaded constructor, because
    // the default constructor will call the constructor for the vector v
    // and start it off empty
    void push(int x) { v.push_back(x); }
    void pop() { v.pop_back(); }
    int top() const { 
        // return what's at the end
        return v[v.size() - 1];
    }
    bool empty() const {
        return v.empty();
    }
    int min() const {
        int min = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < min) {
                min = v[i];
            }
        }
        return min;
    }
private:
    vector<int> v;
};

int main(int argc, char *argv[])
{
    IntStack s; // starts out empty
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "min: " << s.min() << endl;
    
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
