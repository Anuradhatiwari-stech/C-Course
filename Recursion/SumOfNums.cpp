#include <iostream>
using namespace std;


int sumOfNums(int n) {
    // Base case
    if (n == 0) {
        return 0;
    }
    // Recursive case
    return n + sumOfNums(n - 1);
}

int main() {
    int n = 15;
    cout << "Sum of first " << n << " natural numbers is: " << sumOfNums(n) << endl;
    return 0;
}