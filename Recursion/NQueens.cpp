#include <iostream>
#include <vector>
using namespace std;
//     bool isSafe(vector<string>& board, int row, int col, int n){

//         for(int j=0; j<n; j++){
//             if(board[row][j] == 'Q'){
//                 return false;
//             }
//         }
//         for(int i=0; i<n; i++){
//             if(board[i][col] == 'Q'){
//                 return false;
//             }
//         }
//         for(int i=row, j=col; i>=0 && j>=0; i--, j--){
//             if(board[i][j] == 'Q'){
//                 return false;
//             }
//         }
//          for(int i=row, j=col; i>=0 && j<n; i--, j++){
//              if(board[i][j] == 'Q'){
//                 return false;
//              }
//          }
//         return true;
//     }

    
//    void nQueens(vector<string>& board, int row,int n, vector<vector<string>>& ans) {
//     // Base case: If all queens are placed
//      if (row == n) {
//         ans.push_back({board});
//         return;
//      }
//      for (int j = 0; j < n; j++) {
//         // Check if the column and diagonals are free
//         if (isSafe(board,row,j,n)) {
//             // Place the queen
//             board[row][j]='Q';
//             // Recur to place the next queen
//             nQueens(board, row + 1, n, ans);
//             // Backtrack: Remove the queen
//             board[row][j]='.';
//         }
//      }
//    }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n,string(n,'.'));          // Track occupied columns
//         vector<vector<string>> ans; // Track occupied \ diagonals
//         // Track occupied / diagonals
        
//         nQueens(board, 0, n, ans);
//         return ans;
        
//     }

void nQueensUtil(int n, int row, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int& count) {
    // Base case: If all queens are placed
    if (row == n) {
        count++;
        return;
    }
    for (int col = 0; col < n; col++) {
        // Check if the column and diagonals are free
        if (!cols[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
            // Place the queen
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
            // Recur to place the next queen
            nQueensUtil(n, row + 1, cols, diag1, diag2, count);
            // Backtrack: Remove the queen
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }
}

int nQueens(int n) {
    vector<bool> cols(n, false);          // Track occupied columns
    vector<bool> diag1(2 * n - 1, false); // Track occupied \ diagonals
    vector<bool> diag2(2 * n - 1, false); // Track occupied / diagonals
    int count = 0;
    nQueensUtil(n, 0, cols, diag1, diag2, count);
    return count;
}
    // vector<vector<string>> solutions = solveNQueens(n);
    // return solutions.size();
int main() {
    int n = 4; // Size of the chessboard (n x n)
    cout << "Number of ways to place " << n << " queens: " << nQueens(n) << endl;
    return 0;
}