#include <iostream>
#include <vector>
#include <set>
using namespace std;


void mergeSort(vector<int>& arr, int start, int end) {
    // Base case: If the array has one or no elements, it's already sorted
    if (start >= end) {
        return;
    }
    // Find the midpoint of the array
    int mid = start + (end - start) / 2;
    // Recursively sort the left half
    mergeSort(arr, start, mid);
    // Recursively sort the right half
    mergeSort(arr, mid + 1, end);
    // Merge the two sorted halves
    vector<int> merged;
    int left = start;
    int right = mid + 1;
    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            merged.push_back(arr[left]);
            left++;
        } else {
            merged.push_back(arr[right]);
            right++;
        }
    }
    // Copy any remaining elements from the left half
    while (left <= mid) {
        merged.push_back(arr[left]);
        left++;
    }
    // Copy any remaining elements from the right half
    while (right <= end) {
        merged.push_back(arr[right]);
        right++;
    }
    // Copy the merged array back into the original array
    for (int i = 0; i < merged.size(); i++) {
        arr[start + i] = merged[i];
    }
}


int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}