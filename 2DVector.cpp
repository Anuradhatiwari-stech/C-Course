#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <deque>
#include <utility>
using namespace std;


int main(){
    vector<vector<int>> metrix = {
        {1,2,3},
        {4,5,6,2,3},
        {7,8,9}
    };
    for(int i=0;i<metrix.size();i++){
        for(int j=0;j<metrix[i].size();j++){
            cout<<metrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}