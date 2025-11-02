#include <iostream>
#include <vector>
using namespace std;
int recBinarySearch(int arr[], int size, int target, int start, int end) {
    if (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] > target) {
            return recBinarySearch(arr, size, target, start, mid - 1); // Search in the left half
        } else {
            return recBinarySearch(arr, size, target, mid + 1, end); // Search in the right half
        }
    }
    
    return -1; // Target not found
}

    
int main() {
    
   int arr1[] = {-1,0,3,4,5,9,12};
   int target1 = 12;
   int arr2[] = {-2,1,3,4,7,9,12,15};
   int target2 = 3;
    int size = sizeof(arr1)/sizeof(arr1[0]);
    cout<<recBinarySearch(arr1,size,target1,0,size-1)<<endl;

return 0;
}

Peak Index in Mountain Array:

#include <iostream>
#include <vector>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size()-2;
        while(st <= end){
            int mid = st+(end-st)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid;
            }
            if(arr[mid-1]<arr[mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }

    
int main() {
    

    vector<int> arr = {0,3,8,9,5,2};
    cout<<peakIndexInMountainArray(arr) <<endl;
    
return 0;
}
