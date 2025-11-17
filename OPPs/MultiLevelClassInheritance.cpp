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
};

class gradStudent : public Student{
public:
    string specialization;

    gradStudent(string name, int age, int rollNo, string specialization) : Student(){
        this->name = name;
        this->age = age;
        this->rollNo = rollNo;
        this->specialization = specialization;
    }

    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Specialization: " << specialization <<  endl;
    }
};

int main(){
    gradStudent gs1("Aradhya", 24, 501, "Computer Science");
    

    gs1.getInfo();

    return 0;
}
