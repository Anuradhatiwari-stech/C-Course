#include <iostream>
#include <vector>
using namespace std;
#include <cmath>
using namespace std;

int countPrimes(int n) {
        vector<bool>isPrime(n+1,true);
        int count = 0;
        for(int i=2; i<n; i++){
            if(isPrime[i]){
                count++;

                for(int j=i*2; j<n; j=j+i){
                    isPrime[j] = false;
                }
            }
        }
       return count; 
    }
int main() {
    int n=50;
    cout << countPrimes(n) << endl;
    cout << "Prime numbers less than " << n << " are:" << endl;
    for (int i = 2; i < n; i++) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
        }
    }
    cout << endl; 

    return 0;
}