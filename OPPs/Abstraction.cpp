#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Shape{
    public:

    virtual void draw() = 0; // pure virtual function

};

class Circle : public Shape{
    public:

    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape{
    public:

    void draw() {
        cout << "Drawing Rectangle" << endl;
    }
};

int main(){

    Circle c1;
    c1.draw(); // Drawing Circle

    Rectangle r1;
    r1.draw(); // Drawing Rectangle

    return 0;
}