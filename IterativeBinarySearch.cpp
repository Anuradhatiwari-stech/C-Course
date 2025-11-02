#include <iostream>
#include <vector>
using namespace std;
int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // To avoid potential overflow

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

    
int main() {
    
   int arr1[] = {-1,0,3,4,5,9,12};
   int target1 = 15;
   int arr2[] = {-2,1,3,4,7,9,12,15};
   int target2 = 12;
   
   
    cout<<binarySearch(arr1,7,target1)<<endl;
    cout<<binarySearch(arr2,8,target2)<<endl;

return 0;
}
