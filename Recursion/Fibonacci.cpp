#include <iostream>
using namespace std;

int fibonacci(int n) {
// Base case 
    if(n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int n = 10;  // Example: 10th Fibonacci number
    cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << endl;
    return 0;
}