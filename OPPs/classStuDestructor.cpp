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
    // Destructor
    ~Student(){
        delete CgpaPtr; // free the allocated memory
        cout << "Destructor called for " << name << endl;
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

    

    return 0;
}