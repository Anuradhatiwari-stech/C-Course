#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;




int compress(vector<char>& chars) {
        int idx = 0;
        int n = chars.size();
        for(int i=0; i<n; i++){
            char ch = chars[i];
            int count = 0;
            while(i<n && chars[i] == ch){
                count++;
                i++;
            }
            if(count==1){
                chars[idx++]=ch;
            }else{
                chars[idx++]=ch;
                string str= to_string(count);
                for(char dig : str){
                   chars[idx++]=dig;
                }
            }
           
            i--;
        }
        chars.resize(6);
        return idx;
        
    }

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int newLength = compress(chars);
    cout << "New length: " << newLength << endl;
    cout << "Compressed array: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;
    return 0;
}