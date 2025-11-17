#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Teacher {
private:

double salary; // private member

public:

string name;
int age; 
string subject;
string department;

// Teacher (){
//     department = "Computer Science" ; // Default constructor

// }
Teacher(string name, int a, string sub, string dept, double sal){
    this->name = name;
    age = a;
    subject = sub;
    department = dept;
    salary = sal;
} 

Teacher(const Teacher &other){ // Copy constructor
    cout << "Copy constructor called!" << endl;
    this->name = other.name;
    this->age = other.age;
    this->subject = other.subject;
    this->department = other.department;
    this->salary = other.salary;
}

    

    void changeDepartment(const string& newDepartment) {
        department = newDepartment;
    }

    void setSalary(double sal) {
        salary = sal;
    }
    double getSalary() const {
        return salary;
    }

    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Teacher teacher1("Anu Parasar", 22, "C++", "Computer Science", 60000.00);
    teacher1.getInfo();
    Teacher teacher2(teacher1);//Default copy constructor
    // teacher2.getInfo();

    // teacher1.name = "Alice Johnson";
    // teacher1.age = 35;
    // teacher1.subject = "Mathematics";
    // // teacher1.department = "Science";
    // teacher1.setSalary(55000.50);
   
    // cout << "Teacher Name: " << teacher1.name << endl;
    // cout << "Age: " << teacher1.age << endl;
    // cout << "Subject: " << teacher1.subject << endl;
    // cout << "Department: " << teacher1.department << endl;
    // cout << "Salary: $" << teacher1.getSalary() << endl;

    // teacher1.changeDepartment("Mathematics");
    // cout << "Updated Department: " << teacher1.department << endl;

    return 0;
}