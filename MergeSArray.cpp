#include <iostream>
#include <vector>
using namespace std;


void merge(int nums1[], int m, int nums2[], int n ) { // TC=O(m+n), SC=O(1)
        int idx = m+n-1; // last index of merged array
        // merge in reverse order
        int i = m-1, j = n-1;
        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[idx] = nums1[i];
                idx-- , i--;
            }else{
                nums1[idx] = nums2[j];
            j--;
            }
            idx--;
        }
         // if any elements left in nums2
        while(j >= 0){
            nums1[idx] = nums2[j];
            idx--, j--;
        }
    }

    void printArray(int nums1[], int size) { //for printing array
    for (int i = 0; i < size; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    
    
}

int main() {
    int nums1[] = {1,2,3,0,0,0};
    int m = 3;
    int nums2[] = {2,5,6};
    int n = 3;
    int i = m-1, j = n-1;
    merge(nums1, m, nums2, n);
    cout << "Merged array: ";
    printArray(nums1,m+n);
   
      return 0;
}