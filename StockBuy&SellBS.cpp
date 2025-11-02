
#include <iostream>
#include <vector>
using namespace std;


int main() {
    
    vector<int>prices = {7,1,5,3,6,4};
   
        int maxProfit = 0;
        int bestBuy=prices[0];
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            if (prices[i]>bestBuy) {
                maxProfit = max(maxProfit, prices[i]-bestBuy);
            } else {
                bestBuy = prices[i];
                
            }
           
        }
        // return ans;
    cout<<"max Profit:"<< maxProfit << endl;
     
return 0;
}
