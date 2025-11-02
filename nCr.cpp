#include <iostream>
using namespace std;
 int factorialN(int n){
   int fact=1;
   for(int i=1;i<=n;i++){
    fact=fact*i;
    }
    return fact;
 }
 int ncr(int n,int r){
    int fact_n=factorialN(n);
    int fact_r=factorialN(r);
    int fact_nmr=factorialN(n-r);
    return fact_n/(fact_r*fact_nmr);

 }
int main() {
    int n=9,r=3;
    cout << ncr(n,r) << endl;

     return 0;
}
