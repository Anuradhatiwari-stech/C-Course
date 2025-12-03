#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class XYZ {
public:
    

    XYZ() {
       cout << "Constructor called" << endl;
    }

    ~XYZ() {
        cout << "Destructor called" << endl;
    }


};

int main() {
   if (true) {
       static XYZ obj;
   } // Destructor called here when obj goes out of scope

   cout << "End of main function" << endl;

    return 0;
}