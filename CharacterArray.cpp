#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    char str[8];
    cout<<"Enter a string: ";
    cin.getline(str, 8);

    for(char ch:str){
        cout<<ch<<" ";
    }
    cout<<endl;
    // cout<<"Output: "<<str<<endl;

    return 0;
}