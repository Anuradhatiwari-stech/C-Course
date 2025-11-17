#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string name, int age){

        this->name = name;
        this->age = age;
    }
    // Person(){
    //     // default constructor
    // }
};

class Student : public Person{
public:
    int rollNo;

    Student(string name, int age,int rollNo) : Person(name, age){
        // default constructor
        this->rollNo = rollNo;
    }

    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

int main(){
    Student s1("Aradhya", 20, 101);
    

    s1.getInfo();

    return 0;
}