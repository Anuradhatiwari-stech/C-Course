#include <iostream>
#include <vector>
using namespace std;

void printSubsetsUtil(const vector<int>& arr, vector<int>& subset, int i) {
    // Print the current subset
    if(i == arr.size()) {
    cout << "{ ";
    for (int num : subset) {
        cout << num << " ";
    }
    cout << "}" << endl;
    return;
    }
    // Exclude the current element and move to the next
    

    // Generate all subsets
   // for (int i = index; i < arr.size(); i++) {
        // Include arr[i] in the subset
        subset.push_back(arr[i]);
        printSubsetsUtil(arr, subset, i + 1);
        // Backtrack: remove arr[i] from the subset
        subset.pop_back();
        // Exclude arr[i] from the subset
         printSubsetsUtil(arr, subset, i + 1);
    
}

void printSubsets(const vector<int>& arr) {
    vector<int> subset;
    printSubsetsUtil(arr, subset, 0);
}

int main() {
    vector<int> arr = {1, 2, 3};
    cout << "All subsets of the given set are:" << endl;
    printSubsets(arr);
    return 0;
}