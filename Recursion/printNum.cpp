#include <iostream>
using namespace std;

void printNum(int n) {
    // Base case
    if (n == 1) {
        cout<<" 1 "<<endl;
        return;
    }
    cout << n << " ";
    printNum(n - 1); // Recursive call
}

int main() {
    int n = 150;
    printNum(n);
    return 0;
}