#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <deque>
#include <utility>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();
        int sRow = 0, sCol = 0;
        int eRow = m-1, eCol = n-1;
        vector<int> ans;

        while(sRow <= eRow && sCol <= eCol){

            for(int j=sCol; j<=eCol; j++){
                ans.push_back(mat[sRow][j]);
            }
            for(int i=sRow+1; i<=eRow; i++){
                ans.push_back(mat[i][eCol]);
            }
            for(int j=eCol-1; j>=sCol; j--){
                if( sRow == eRow){
                    break;
                }
                ans.push_back(mat[eRow][j]);
            }
            for(int i=eRow-1; i>=sRow+1; i--){
                if( sCol == eCol){
                    break;
                }
                ans.push_back(mat[i][sCol]);
            }
            sRow++; eRow--;
            sCol++; eCol--;
        }  

        return ans;
    }

int main(){ 
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> result = spiralOrder(matrix);
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}