 #include <iostream>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <list>
 #include <deque>
 #include <utility>

 using namespace std;


int getDiagonalSum(int matrix[4][4], int row, int col) {
     int primaryDiagonalSum = 0;
     int secondaryDiagonalSum = 0;
    // int diagonalSum = 0;

    for (int i = 0; i < row; i++) {
        // for(int j=0;j<col;j++){
            // if(i==j || (i+j)==col-1){
        //     if(i == j){
        //         diagonalSum+=matrix[i][j]; // Primary diagonal
        //     }
        //     else if(j == (col - i - 1)){
        //         diagonalSum+=matrix[i][j]; // Secondary diagonal
        //     }
        // }
        primaryDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][col - i - 1];
    }

    return primaryDiagonalSum + secondaryDiagonalSum;
}

int main(){

    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    // int matrix[4][3];
    int row = 4;
    int col = 4;

    cout << "Sum of both diagonals is: " << getDiagonalSum(matrix, row, col) << endl;

    return 0;
}