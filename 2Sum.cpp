#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <deque>
#include <utility>
#include <unordered_map>
using namespace std;

 vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>m;
        vector<int>ans;
        for(int i=0; i<=n-1; i++){

            int first = nums[i];
            int second = target-first;
            if(m.find(second) != m.end()){
               ans.push_back(i);
               ans.push_back(m[second]);
               break;
            }
            m[first]=i;
        }
        return ans;
    }

int main(){ 
    vector<int> nums = {2,7,11,15};
    int target = 9; 
    vector<int> result = twoSum(nums, target);
    cout << "Indices of the two numbers that add up to " << target << " are: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}