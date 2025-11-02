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

bool comparator(pair<int,int>p1, pair<int,int>p2){
    if(p1.second<p2.second){
        return true;
    }else if(p1.second>p2.second){
        return false;
    }else{
        return p1.first<p2.first;   
}
}
int main(){

vector <int> vec ={4,1,5,2,3,6,9};
int target=5;

cout<<binary_search(vec.begin(),vec.end(),target)<<endl; //O(logn

cout<<"Max: "<<*max_element(vec.begin(),vec.end())<<endl;
cout<<"Min: "<<*min_element(vec.begin(),vec.end())<<endl;

// reverse(vec.begin(),vec.end()); //O(n)
// // vector<pair <int, int>> vec ={ {1,2}, {3,4}, {0,5},{4,5}, {2,3} };

// // sort(vec.begin(),vec.end(), greater<int>()); //for descending order
// //  sort(vec.begin(),vec.end(), comparator); //O(nlogn)
// // sort(arr,arr+9); //O(nlogn)
// for(int val: vec){
//     cout<< val <<" ";
// }
// cout<<endl;
// string s= "abdc";
// next_permutation(s.begin(),s.end());
// prev_permutation(s.begin(),s.end());
// cout<<s<<endl;
    return 0;
}