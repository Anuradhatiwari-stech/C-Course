#include <iostream>
#include <vector>
using namespace std;

void ratInAMazeUtil(vector<vector<int>>& maze, int row, int col, vector<vector<int>>& solution) {
    int n = maze.size();
    // Base case: If (row, col) is the destination
    if (row == n - 1 && col == n - 1) {
        solution[row][col] = 1;
        return;
    }
    // Check if maze[row][col] is a valid move
    if (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1) {
        // Mark row, col as part of the solution path
        solution[row][col] = 1;
        // Move forward in row direction
        ratInAMazeUtil(maze, row + 1, col, solution);
        // Move down in y direction
        ratInAMazeUtil(maze, row, col + 1, solution);
        // Backtrack: unmark row, col as part of the solution path
        solution[row][col] = 0;
    }
}

void ratInAMaze(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<vector<int>> solution(n, vector<int>(n, 0));
    ratInAMazeUtil(maze, 0, 0, solution);
    // Print the solution matrix
    cout << "Solution Path (1 indicates the path taken by the rat):" << endl;
    for (const auto& row : solution) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    ratInAMaze(maze);
    return 0;
}