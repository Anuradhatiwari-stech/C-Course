#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n) { //for printing array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insertionSort(int arr[], int n) { // O(n^2)
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        // while (prev >= 0 && arr[prev] > curr) { //for ascending order
        while (prev >= 0 && arr[prev] < curr) { //for descending order
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;  // Place curr at its correct position
    }
}   


int main() {
    int arr[] = {4,1,5,2,3,6,9,8,7};
    int n = 9;
    insertionSort(arr, n);
    printArray(arr, n);
   
      return 0;
}