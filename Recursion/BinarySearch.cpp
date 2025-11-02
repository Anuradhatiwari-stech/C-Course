#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int>& arr, int target, int s, int e) { //TC: O(log n), SC: O(log n) due to recursion stack
    // Base case
    if (s > e) {
        return -1; // Target not found
    }
    int mid = s + (e - s) / 2;
    // Recursive case
    if (arr[mid] == target) {
        return mid; // Target found
    } else if (arr[mid] < target) {
        return binarySearch(arr, target, mid + 1, e); // Search in the right half
    } else {
        return binarySearch(arr, target, s, mid - 1); // Search in the left half
    }
}

int main() {
    vector<int> arr = {-1,0,3,4,5,9,12};
    int target = 9;
    int result = binarySearch(arr, target, 0, arr.size() - 1);
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found." << endl;
    }
    return 0;
}