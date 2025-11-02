#include <iostream>
#include <vector>
using namespace std;

void getPermutationsUtil(vector<int>& arr, int index, vector<vector<int>>& result) {
    // Base case: if the current index is at the end of the array
    if (index == arr.size()) {
        result.push_back(arr); // Store the current permutation
        return;
    }
    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]); // Swap to create a new permutation
        getPermutationsUtil(arr, index + 1, result); // Recurse for the next index
        swap(arr[index], arr[i]); // Backtrack to restore the original array
    }
}

vector<vector<int>> getPermutations(vector<int>& arr) {
    vector<vector<int>> result;
    getPermutationsUtil(arr, 0, result);
    return result;
}


int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> permutations = getPermutations(arr);
    
    cout << "All permutations of the given set are:" << endl;
    for (const auto& perm : permutations) {
        cout << "{ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}