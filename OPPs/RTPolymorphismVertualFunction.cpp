#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Parent{
    public:

    virtual void showInfo(){
        cout << "Parent class showInfo function called" << endl;
    }
};

class Child : public Parent{
    public:

    void showInfo() {
        cout << "Child class showInfo function called" << endl;
    }
};

int main(){

    // Parent p1;
    // p1.showInfo(); // Parent class showInfo function called

    Child c1;
    c1.showInfo(); // Child class showInfo function called

    return 0;
}