#include <iostream>
#include <vector>
using namespace std;


bool isSortedArray(int arr[], int n) {
    // Base case
    if (n == 0 || n == 1) {
        return true;
    }
    // Recursive case
    if (arr[0] > arr[1]) { //for ascending order
    // if (arr[0] < arr[1]) { //for descending order
        return false;
    } else {
        return isSortedArray(arr + 1, n - 1);
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    if (isSortedArray(arr, n)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }
    return 0;
}