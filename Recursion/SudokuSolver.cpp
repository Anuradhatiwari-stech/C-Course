#include <iostream>
#include <vector>
using namespace std;

// void sudokuSolver(vector<vector<char>>& board, vector<vector<bool>>& rows,
//                    vector<vector<bool>>& cols, vector<vector<bool>>& boxes,
//                    int row, int col, bool& solved) {
//     // If we have reached the end of the board, mark as solved
//     if (row == 9) {
//         solved = true;
//         return;
//     }
//     // Move to the next row if we reach the end of the current row
//     if (col == 9) {
//        sudokuSolver(board, rows, cols, boxes, row + 1, 0, solved);
//        if (solved) return;   // <-- important fix!
//        return;
//    }
//     // If the cell is already filled, move to the next cell
//     if (board[row][col] != '.') {
//         sudokuSolver(board, rows, cols, boxes, row, col + 1, solved);
//         return;
//     }

// //     if (board[row][col] == '.') {
// //         cout << "Trying position (" << row << "," << col << ")\n";
// //    }

//     // Try placing numbers 1-9 in the empty cell
//     for (char num = '1'; num <= '9'; num++) {
//         int boxIndex = (row / 3) * 3 + (col / 3);
//         if (!rows[row][num - '1'] && !cols[col][num - '1'] && !boxes[boxIndex][num - '1']) {
//             // Place the number
//             board[row][col] = num;
//             rows[row][num - '1'] = true;
//             cols[col][num - '1'] = true;
//             boxes[boxIndex][num - '1'] = true;

//             // Recur to place the next number
//             sudokuSolver(board, rows, cols, boxes, row, col + 1, solved);
//             if (solved) return; // If solved, no need to backtrack

//             // Backtrack
//             board[row][col] = '.';
//             rows[row][num - '1'] = false;
//             cols[col][num - '1'] = false;
//             boxes[boxIndex][num - '1'] = false;
//         }
//     }
// }

// void solveSudoku(vector<vector<char>>& board) {
//     vector<vector<bool>> rows(9, vector<bool>(9, false));
//     vector<vector<bool>> cols(9, vector<bool>(9, false));
//     vector<vector<bool>> boxes(9, vector<bool>(9, false));

//     // Initialize the tracking arrays based on the initial board state
//     for (int i = 0; i < 9; i++) {
//         for (int j = 0; j < 9; j++) {
//             if (board[i][j] != '.') {
//                 int num = board[i][j] - '1';
//                 int boxIndex = (i / 3) * 3 + (j / 3);
//                 rows[i][num] = true;
//                 cols[j][num] = true;
//                 boxes[boxIndex][num] = true;
//             }
//         }
//     }

//     bool solved = false;
//     sudokuSolver(board, rows, cols, boxes, 0, 0, solved);
// }

bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        for(int j=0; j<9; j++){
            if(board[row][j] == dig){
                return false;
            }
        }
        for(int i=0; i<9; i++){
            if(board[i][col] == dig){
                return false;
            }
        }
        int srow = (row/3)*3, scol = (col/3)*3;
        for(int i=srow; i<=srow+2; i++){
            for(int j=scol; j<=scol+2; j++)
            if(board[i][j] == dig){
                return false;
            }
        }
        return true;
}
    bool helper(vector<vector<char>>& board, int row, int col){

        if(row == 9){
            return true;
        } 
        int nextRow = row;
        int nextCol = col+1;
        if(nextCol == 9){
            nextRow = row+1;
            nextCol = 0;
        }
        if(board[row][col] != '.'){
            return helper(board, nextRow, nextCol);
        }
        for(char dig='1'; dig<='9'; dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col] = dig;
                if(helper(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {

        helper(board,0,0);
        
    }

int main() {
    vector<vector<char>> board = {
        {'.', '7', '.', '.', '4', '.', '.', '5', '.'},
        {'.', '6', '.', '9', '.', '.', '.', '.', '2'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '4', '.', '.', '6', '.', '.', '.', '9'},
        {'.', '.', '.', '.', '1', '.', '.', '.', '8'},
        {'6', '1', '.', '.', '5', '.', '2', '.', '.'},
        {'.', '.', '7', '4', '.', '.', '8', '.', '.'},
        {'8', '.', '1', '.', '.', '.', '.', '.', '.'},
        {'.', '2', '.', '3', '.', '.', '.', '.', '7'}
    };
    // cin>>ws;
    // vector<vector<char>> board(9, vector<char>(9));
    // for(int i=0;i<9;i++){
    //     for(int j=0;j<9;j++){
    //         cin>>board[i][j];
    //     }
    // }

    solveSudoku(board);

    cout << "Solved Sudoku Board:" << endl;
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}