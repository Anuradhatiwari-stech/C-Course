#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;



class Student {
public:
    string name;
    int rollNo;
};

class Teacher {
public:
    string subject;
    double salary;
};

class TA : public Student, public Teacher {
public:
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    TA ta1;
    ta1.name = "Aradhya";
    ta1.rollNo = 501;
    ta1.subject = "Data Structures";
    ta1.salary = 1500.50;

    ta1.getInfo();

    return 0;
}