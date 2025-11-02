#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


void printDigits(int n){
    int count=0;
    int sum=0;

    while(n>0){
        int digit= n % 10;
        cout<<digit<<endl;
        n=n/10;
        count++;
        sum=sum+digit;
        
    }
    cout<<"No of digits: "<<count<<endl;
    cout<<"Sum of digits: "<<sum<<endl;
    return;
}

int main() {
    int n=12345;
    printDigits(n);
   
      return 0;
}

