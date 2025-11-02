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
unordered_map<string,int>m;
// m["TV"]=100;
// m["Laptop"]=60;
// m["Mobile"]=20;


m.insert({"TV",100});
m.insert({"Laptop",60});
m.insert({"Mobile",20});
m.insert({"Tablet",30});
m.insert({"Laptop",70}); //multimap allows duplicate keys
// m.emplace("Earphones",10); //faster than insert, in-place object creation
m.erase("Mobile");

for(auto p:m){
    cout<<p.first<<" "<<p.second<<endl;
}   

// cout<<"Count: "<<m.count("Tablet")<<endl;
// cout<<"Count: "<<m["Laptop"]<<endl;
// if(m.find("Laptop")!=m.end()){
//     cout<<"Laptop is present"<<endl;
// }else{
//     cout<<"Laptop is not present"<<endl;
// }


    return 0;
}