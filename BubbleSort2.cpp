#include <iostream>
#include <vector>
using namespace std;
void bubbleSort( int arr[], int n){ // O(n^2)
    for (int i = 0; i < n - 1; i++) {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { //for descending order
            // if (arr[j] > arr[j + 1]) { //for ascending order
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped) {
            return; // Array is already sorted
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4,1,5,2,3};
    int n = 5;
    bubbleSort(arr, n);
    printArray(arr, n);
   
      return 0;
}