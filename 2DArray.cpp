#include <iostream>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <list>
 #include <deque>
#include <utility>

using namespace std;

int getMaxSum(int matrix[4][4], int row, int col) {
    int maxSum = INT_MIN;

    for (int i = 0; i < col; i++) {
        int currentSum = 0;
        for (int j = 0; j < row; j++) {
            currentSum += matrix[i][j];
        }
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

// pair<int,int> searchMatrix(int matrix[3][4], int row, int col, int target) {
//     int start = 0;
//     int end = row * col - 1;


//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//            if(matrix[i][j] == target){
//             return make_pair(i,j);
//            }
        
//         }
        
//     }

//     return make_pair(-1,-1); // Target not found
// }


int main(){

    int matrix[4][4] = {{1,2,3,40},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    // int matrix[4][3];
    int row = 4;
    int col = 4;
    // int target=10;

    cout << "Maximum row sum is: " << getMaxSum(matrix, row, col) << endl;

    // pair<int, int> pos = searchMatrix(matrix, row, col, target);
    // if (pos.first != -1) {
    //     cout << "Element found at: (" << pos.first << ", " << pos.second << ")" << endl;
    // } else {
    //     cout << "Element not found" << endl;
    // }
    // matrix[1][2] = 10; //for change the value of cell
 
    // for(int i=0;i<row;i++){ //input
    //      for(int j=0;j<col;j++){
    //          cin>>matrix[i][j];
    //      }
    //  }

    // cout<< matrix[1][2]<<endl;
    // cout<< matrix[2][3]<<endl;
    //linear search 
 
   
    // for(int i=0;i<row;i++){ //output
    //      for(int j=0;j<col;j++){
    //          cout<<matrix[i][j]<<" ";
    //      }
    //      cout<<endl;
    //  }
    return 0;

}


