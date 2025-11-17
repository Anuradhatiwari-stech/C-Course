#include <iostream>
#include <vector>
#include <set>
using namespace std;


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // Choosing the last element as pivot
        int i = low - 1; // Pointer for the smaller element
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]); // Place pivot in the correct position
        int pivotIndex = i + 1;

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
    