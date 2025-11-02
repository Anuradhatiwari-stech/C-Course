#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
} 

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // To avoid overflow
}

int main() {
    int a = 56, b = 98;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    cout << "LCM of " << a << " and " << b << " is: " << lcm(a, b) << endl;
    return 0;
}