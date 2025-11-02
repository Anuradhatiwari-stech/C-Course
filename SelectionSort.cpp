#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionSort(int arr[], int n) { // O(n^2)
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  //Unsorted part starting index
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[minIndex]) { //for descending order
            // if (arr[j] < arr[minIndex]) { //for ascending order
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}


int main() {
    int arr[] = {4,1,5,2,3,6,9,8,7};
    int n = 9;
    selectionSort(arr, n);
    printArray(arr, n);
   
      return 0;
}