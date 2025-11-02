#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>>& maze, int row, int col,string path, vector<string>& ans, vector<vector<bool>>& visited) {
    int n = maze.size();
    if(row<0 || col<0 || row>=n || col>=n || maze[row][col]==0 || visited[row][col]==true){
        return;
    }
    if(row==n-1 && col==n-1){
        ans.push_back(path);
        return;
    }
    visited[row][col]=true;
    helper(maze, row-1, col, path+'U', ans, visited);
    helper(maze, row+1, col, path+'D', ans, visited);
    helper(maze, row, col-1, path+'L', ans, visited);
    helper(maze, row, col+1, path+'R', ans, visited);
    visited[row][col]=false;
}
    // Base case: If (row, col) is the destination
    
vector<string> findPaths(vector<vector<int>>& maze) {
    vector<string> ans;
    int n = maze.size();
    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    helper(maze, 0, 0, "", ans, visited);
    return ans;
}


int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    vector<string> paths = findPaths(maze);
    cout << "All possible paths from start to destination are:" << endl;
    for (const string& path : paths) {
        cout << path << endl;   
        cout << endl; // Separate different solutions
    }
    return 0;
}