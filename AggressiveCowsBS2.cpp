#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int N,int C, int minAllowedDist) {
    int cows = 1, lastStallPos = arr[0];
    for (int i = 1; i < N; i++){
        if (arr[i] - lastStallPos >= minAllowedDist) {
            cows++;
        
            lastStallPos = arr[i];
        }
        if (cows == C) return true;
    }
    return false;
}


int getDistance(vector<int> &arr, int N, int C) {
    sort(arr.begin(),arr.end());
    int st = 0, end = arr[N - 1] - arr[0];
    int ans = -1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isPossible(arr, N, C, mid)) {
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;  
        }
    }
    return ans;
}


int main() {
    vector<int> arr = {1, 2, 4, 8, 9};
    int C = 3;
    int N = arr.size();
    cout << "The largest minimum distance is: " << getDistance(arr, N, C) << endl;
    return 0;
}
    
