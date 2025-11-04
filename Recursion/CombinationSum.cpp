#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s;
void getAllCombinations(int idx, int target, vector<int>& arr, vector<int>& combin, vector<vector<int>>& ans) {
    // Base case: if target is met, add the combin combination to the ans
    if (target == 0) {
        if(s.find(combin) == s.end()){
              ans.push_back(combin);
              s.insert(combin);
          }   
    }
    // If target becomes negative or we reach the end of arr, return
    if (target < 0 || idx == arr.size()) {
        return;
    }
    // Include the combin arr[i] array element
    combin.push_back(arr[idx]);
    getAllCombinations(idx, target - arr[idx], arr, combin, ans);
    getAllCombinations(idx+1, target - arr[idx], arr, combin, ans);
    // Backtrack: remove the last added arr
    combin.pop_back();
    // Exclude the combin arr and move to the next
    getAllCombinations(idx + 1, target, arr, combin, ans);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> combin;
    getAllCombinations(0, target, arr, combin, ans);
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 6, 7};
    int target = 9;
    vector<vector<int>> result = combinationSum(arr, target);
    cout << "Combinations that sum to " << target << " are:\n";
    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}