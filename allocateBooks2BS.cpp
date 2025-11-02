#include <iostream>
#include <vector>
using namespace std;

// function to check if it is possible to allocate books such that / checking the validity
bool isValid(vector<int>& arr, int n,int m,int maxAllocatedPages) {
    int students = 1, pages = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > maxAllocatedPages) return false;
        
        if(pages+arr[i] <= maxAllocatedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
            if(students > m) return false;
        }
    }
    return true;
}

// finding the minimum number of maximum pages
int allocateBooks(vector<int>& arr, int n, int m) {
    if (n < m) {
        return -1;
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int start = 0, end = sum; //range
    int ans = -1;
    

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, m, mid)) { // left search
            ans = mid;
            end = mid - 1;
        } else { // right search
            start = mid + 1;
        }
    }
    return ans;
}
    
    
int main() {
    

    vector<int> arr = {2,1,3,4};
    int n = arr.size();
    int m = 2;
    cout << allocateBooks(arr,n,m) << endl;
    
return 0;
}