#include <iostream>
#include <vector>
#include <set>
using namespace std;

int countInversionsUtil(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    int invCount = 0;
    invCount += countInversionsUtil(arr, left, mid);
    invCount += countInversionsUtil(arr, mid + 1, right);

    // Merge step
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            invCount += (mid - i + 1); // Count inversions
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
    return invCount;
}

int countInversions(vector<int>& arr) {
    return countInversionsUtil(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int inversionCount = countInversions(arr);
    cout << "Number of inversions: " << inversionCount << endl;
    return 0;
}