#include <iostream>
using namespace std;

int binaryToDec(int binNum) {
    int ans = 0;
    int power = 1;
    while(binNum > 0){
       int rem = binNum % 10;
        ans += (rem*power);

        binNum /= 10;
        power *= 2;
    }
return ans;

}

int main() {
    // for (int i = 0; i < 16; i++)
   
    cout  << binaryToDec(11011001) << endl;
    return 0;
}