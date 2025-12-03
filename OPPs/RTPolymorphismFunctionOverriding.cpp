#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Parent{
    public:
    void getInfo(){
        cout << "Parent class show function called" << endl;
    }
};

class Child : public Parent{
    public:
    void getInfo(){
        cout << "Child class show function called" << endl;
    }
};

int main(){

    // Child c1;
    // c1.getInfo(); // Child class show function called

    Parent p1;
    
    p1.getInfo(); // Parent class show function called

    return 0;
}