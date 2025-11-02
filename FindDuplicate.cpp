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

int findDuplicate(vector<int>& nums) {
    // Floyd's Tortoise and Hare (Cycle Detection) Algorithm, TC: O(n), SC: O(1)
        // int slow = nums[0];
        // int fast = nums[0]; 
        // do{
        //     slow=nums[slow];
        //     fast=nums[nums[fast]];
            
        // }while(slow != fast);
        // slow=nums[0];

        // while(slow != fast){
        //     slow = nums[slow];
        //     fast = nums[fast];
        // }
        // return slow;
        // Using Hashing, TC: O(n), SC: O(n)
        unordered_set<int>s;
        for(int val:nums){
            if(s.find(val) != s.end()){
                return val;
            }
            s.insert(val);
        }
        return -1;
        
    }

int main(){ 
    vector<int> nums = {1,3,4,2,2};
    // int duplicate = findDuplicate(nums);
    cout << "The duplicate number is: " << findDuplicate(nums) << endl;
    return 0;
}