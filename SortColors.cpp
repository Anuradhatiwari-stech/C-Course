#include <iostream>
#include <vector>
using namespace std;


void sortColors(int arr[], int n) { // O(n)
    int n = arr.size();
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count0++;
        } else if (arr[i] == 1) {
            count1++;
        } else {
            count2++;
        }
    }  
    // Reconstruct the array/overwrite the array
    int index = 0;
    for (int i = 0; i < count0; i++) {
        arr[index++] = 0;
    }
    for (int i = 0; i < count1; i++) {
        arr[index++] = 1;
    }
    for (int i = 0; i < count2; i++) {
        arr[index++] = 2;  
    }

        
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2,0,2,1,0,1,2,0,1,1,0};
    int n = 11;
    sortColors(arr, n);
    printArray(arr, n);
   
      return 0;
}