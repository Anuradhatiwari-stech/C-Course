#include <iostream>
#include <vector>
using namespace std;





void nextPermutation(int nums[], int n) { // O(n)
        int pivot= 1, n = nums.size();
        for(int i = n-2; i >= 0; i--){ // find pivot
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            } 
        }
        if(pivot == -1){
            reverse(nums.begin(), nums.end()); //In place reversal
            return;        
        }
        for(int i = n-1; i > pivot; i--){ // find just larger element
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]); 
                break;
            }
        }
        int i = pivot+1, j = n-1;
        while(i <=j){ // reverse the suffix
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        
    }
 void printArray(int nums[], int size) { //for printing array
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    
}

int main() {
    int nums[] = {1,2,3,6,5,4};
    
    nextPermutation(nums, n);
    cout << "Next permutated array: ";
    printArray(nums,n);
   
      return 0;
}