#include <iostream>
#include <vector>
using namespace std;

// function to check if it is possible to allocate books such that / checking the validity
bool isValid(vector<int>& arr, int n,int m,int maxAllocatedPages) {
    int studentsRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + arr[i] > maxAllocatedPages) {
            studentsRequired++;
            currentSum = arr[i];
            if (studentsRequired > m) {
                return false;
            }
        } else {
            currentSum += arr[i];
        }
    }
    return true;
}

// finding the minimum number of maximum pages
int allocateBooks(vector<int>& arr, int n, int m) {
    if (n < m) {
        return -1;
    }
    int start = 0, end = 0; //range
    int result = -1;

    for (int i = 0; i < n; i++) {
        end += arr[i];
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, m, mid)) { // left search
            result = mid;
            end = mid - 1;
        } else { // right search
            start = mid + 1;
        }
    }
    return result;
}
    
int main() {
    

    vector<int> arr = {2,1,3,4};
    int n = arr.size();
    int m = 2;
    cout << allocateBooks(arr,n,m) << endl;
    
return 0;
}