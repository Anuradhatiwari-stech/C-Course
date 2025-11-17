#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Person{
public:
    string name;
    int age;
};

class Student : public Person{
public:
    int rollNo;

    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

class Teacher : public Person{
public:
    string subject;
    double salary;

    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main(){

    Student s1;
    s1.name = "Aradhya";
    s1.age = 20;
    s1.rollNo = 101;
    s1.getInfo();
    cout << endl;

    Teacher t1;
    t1.name = "Ankit";
    t1.age = 30;
    t1.subject = "Mathematics";
    t1.salary = 50000.75;

    t1.getInfo();

    return 0;
}
