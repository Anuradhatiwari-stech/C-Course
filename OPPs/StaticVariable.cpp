#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


// Static Variable Example in Function
void Func(){

    static int x = 0; // static variable
    cout << "x: " << x << endl;
    x++;
}

//Static Variable Example in Class
class A {
    public:
    int x; // static variable declaration

    void incrementX() {
        x++;
    }

};

int main(){

    Func(); // x: 0
    Func(); // x: 1
    // Func(); // x: 2
    // Func(); // x: 3

    A a1;
    a1.x = 0; // static variable definition and initialization
    cout << "a1: " << a1.x << endl; // a1: 0
    a1.incrementX();
    cout << "a1: " << a1.x << endl; // a1: 1

    return 0;
}