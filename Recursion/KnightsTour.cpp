#include <iostream>
#include <vector>
#include <set>
using namespace std;

// void knightsTourUtil(int row, int col, int moveCount, vector<vector<int>>& board,
//                      vector<int>& rowMoves, vector<int>& colMoves, int n, bool& solved) {
//     // Base case: If all squares are visited
//     if (moveCount == n * n) {
//         solved = true;
//         return;
//     }
//     // Try all possible knight moves
//     for (int i = 0; i < 8; i++) {
//         int nextRow = row + rowMoves[i];
//         int nextCol = col + colMoves[i];
//         // Check if the move is valid
//         if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && board[nextRow][nextCol] == -1) {
//             board[nextRow][nextCol] = moveCount;
//             knightsTourUtil(nextRow, nextCol, moveCount + 1, board, rowMoves, colMoves, n, solved);
//             if (solved) return; // If solved, no need to backtrack
//             // Backtrack
//             board[nextRow][nextCol] = -1;
//         }
//     }
// }

// void knightsTour(int n) {
//     vector<vector<int>> board(n, vector<int>(n, -1));
//     // Possible moves for a knight
//     vector<int> rowMoves = {-2, -1, 1, 2, 2, 1, -1, -2};
//     vector<int> colMoves = {1, 2, 2, 1, -1, -2, -2, -1};

//     // Starting position
//     board[0][0] = 0;
//     bool solved = false;
//     knightsTourUtil(0, 0, 1, board, rowMoves, colMoves, n, solved);

//     if (solved) {
//         cout << "Knight's Tour solution:" << endl;
//         for (const auto& row : board) {
//             for (int cell : row) {
//                 cout << cell << "\t";
//             }
//             cout << endl;
//         }
//     } else {
//         cout << "No solution exists for the Knight's Tour." << endl;
//     }
// }

 bool isValid(vector<vector<int>>& grid, int r, int c,int n, int expVal){
        
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != expVal){
            return false;
        }
        if(expVal == n*n-1){
            return true;
        }

        int ans1 = isValid(grid, r-2, c+1, n, expVal+1);
        int ans2 = isValid(grid, r-1, c+2, n, expVal+1);
        int ans3 = isValid(grid, r+1, c+2, n, expVal+1);
        int ans4 = isValid(grid, r+2, c+1, n, expVal+1);
        int ans5 = isValid(grid, r+2, c-1, n, expVal+1);
        int ans6 = isValid(grid, r+1, c-2, n, expVal+1);
        int ans7 = isValid(grid, r-1, c-2, n, expVal+1);
        int ans8 = isValid(grid, r-2, c-1, n, expVal+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
       return  isValid(grid, 0, 0, grid.size(),0);
        
        
    }

int main() {
    vector<vector<int>> grid = {
        {0, 59, 38, 33, 30, 17, 8, 63},
        {37, 34, 31, 60, 9, 62, 29, 16},
        {58, 1, 36, 39, 32, 27, 18, 7},
        {35, 48, 41, 26, 61, 10, 15, 28},
        {42, 57, 2, 49, 40, 23, 6, 19},
        {47, 50, 45, 54, 25, 20, 11, 14},
        {56, 43, 52, 3, 22, 13, 24, 5},
        {51, 46, 55, 44, 53, 4, 21, 12}
    };
    if (checkValidGrid(grid)) {
        cout << "The grid represents a valid Knight's Tour." << endl;
    } else {
        cout << "The grid does not represent a valid Knight's Tour." << endl;
    }
    return 0;
}   