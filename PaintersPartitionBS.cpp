include <iostream>
#include <vector>
using namespace std;

// function to check if it is possible to allocate books such that / checking the validity
bool isPossible(vector<int>& arr, int n,int m,int maxAllocatedTime) {
    int painters = 1, time = 0;
    for(int i = 0; i < n; i++) {
        // if((arr[i]) > maxAllocatedTime) return false;
        
        if(time+arr[i] <= maxAllocatedTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
            // if(painters > m) return false;
        }
    }
    return painters <= m;
}

// finding the minimum number of maximum pages
int minTimeToPaint(vector<int>& arr, int n, int m) {
    if (n < m) {
        return -1;
    }
    int sum = 0, maxVal = INT_MIN;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    int start = maxVal, end = sum; //range
    int ans = -1;
    

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid)) { // left search
            ans = mid;
            end = mid - 1;
        } else { // right search
            start = mid + 1;
        }
    }
    return ans;
}
    
    
int main() {
    

    vector<int> arr = {40,30,10,20};
    int n = arr.size();
    int m = 2;
    cout<< minTimeToPaint(arr,n,m);
    
return 0;
}