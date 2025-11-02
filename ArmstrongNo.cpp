#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool isArmstrong(int n){
    int originalNum=n;
    int sum=0;
    int digits=0;
    while(n>0){
        digits++;
        n=n/10;
    }
    n=originalNum;
    while(n>0){
        int digit=n%10;
        sum=sum+pow(digit,digits);
        n=n/10;
    }
    return (sum==originalNum);
}

int main() {
    int n=371;
    if(isArmstrong(n)){
        cout<<n<<" is an Armstrong number"<<endl;
    }else{
        cout<<n<<" is not an Armstrong number"<<endl;
    }
   
      return 0;
}