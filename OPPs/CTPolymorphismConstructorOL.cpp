#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;



class Student {
public:
    string name;
    int rollNo;

    Student(){
        cout << "Non Parameterized Constructor called" << endl;
    }

    Student(string name, int rollNo){
        this->name = name;
        this->rollNo = rollNo;
        cout << "Parameterized Constructor called" << endl;
    }
};



int main(){

    // Student s1;
    // s1.name = "Aradhya";
    // cout << "Student Name: " << s1.name << endl;

    Student s2("Ankit", 102);
    cout << "Student Name: " << s2.name << endl;
    cout << "Student Roll No: " << s2.rollNo << endl;

    return 0;
}