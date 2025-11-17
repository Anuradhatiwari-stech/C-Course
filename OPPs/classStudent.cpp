#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Student{
    public:
    string name;
    double* CgpaPtr;
    int rollNo;

    Student(string name, int rollNo, double cgpa){
        this->name = name;
        this->rollNo = rollNo;
        CgpaPtr = new double; // dynamic memory allocation
        *CgpaPtr = cgpa;
    }
    // Copy constructor
    Student(const Student &obj){
        this->name = obj.name;
        this->rollNo = obj.rollNo;
        this->CgpaPtr = new double; // allocate new memory
        *(this->CgpaPtr) = *(obj.CgpaPtr); // copy the value    
    }

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << *CgpaPtr << endl;
    }
};


int main(){
    Student s1("Aradhya", 101, 9.1);
    cout << "Student 1 Info:" << endl;
    s1.displayInfo();

    // Using copy constructor
    Student s2 = s1; // or Student s2(s1);
    cout << "\nStudent 2 Info (after copy):" << endl;
    s2.displayInfo();

    // Modifying s2's CGPA to show deep copy
    *(s2.CgpaPtr) = 8.5;
    cout << "\nAfter modifying Student 2's CGPA:" << endl;
    cout << "Student 1 Info:" << endl;
    s1.displayInfo();
    s2.name = "Rahul";
    cout << "Student 2 Info:" << endl;
    s2.displayInfo();

    return 0;
}

