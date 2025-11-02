#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <deque>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {

     
        sort(nums.begin(),nums.end());
        int n=nums.size();
          vector<vector<int>>ans;
        
        

        for(int i=0; i<n; i++){

            if(i>0 && nums[i] == nums[i-1])    continue;
            
            int j=i+1, k=n-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];

                if(sum<0){
                  j++;  
                } else if(sum>0){
                  k--; 
                } else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++, k--;

                    while(j<k && nums[j] == nums[j-1]) j++;
                    
                }
            }
        }
        
      
        return ans;
    

        //  int n=nums.size();
        
        // set<vector<int>>uniqueTriplets;

        // for(int i=0; i<n; i++){
        //     int target = -nums[i];
        //     set<int>s;

        //     for(int j=i+1; j<n; j++){

        //         int toFind = target-nums[j];

        //         if(s.find(toFind) != s.end()){
        //             vector<int>triplet = {nums[i],nums[j],toFind};
        //             sort(triplet.begin(),triplet.end());

        //             uniqueTriplets.insert(triplet);
                    
        //         }
        //         s.insert(nums[j]);
        //     }
        // }  
        // vector<vector<int>>ans(uniqueTriplets.begin(),uniqueTriplets.end());
        // return ans;
            
    }


int main(){ 
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    cout << "Unique triplets that sum to zero are:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}   