#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main(){
    vector<pair<int,int>>vec = {{1,2},{3,4},{5,6}};
    vec.push_back({6,7});
    vec.emplace_back(8,9); //faster than push_back, in-place object creation
    // for(int i=0;i<vec.size();i++){
    for(auto p:vec){
        cout<<p.first<<" "<<p.second<<endl;
        // cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    // pair<int,int>p=make_pair(1,3);
    // cout<<p.first<<" "<<p.second<<endl;
    // pair<int,pair<int,int>>p1=make_pair(1,make_pair(2,3));
    // cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;  

    return 0;
}