
#include <iostream>
#include <vector>
using namespace std;

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[] = {16, 5, 23, 9, 7,8,10};
    int size = 7;
    
    reverseArray(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }     cout << endl;
    
return 0;
}