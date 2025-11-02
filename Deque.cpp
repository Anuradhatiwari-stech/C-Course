#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;


int main(){
deque<int>d;
d.push_back(1);
d.push_back(2);
d.push_front(3);
d.push_front(4);
d.emplace_back(5);
d.emplace_front(6);
d.pop_back();
d.pop_front();

d.emplace(d.begin(),7); //insert 7 at beginning
d.emplace(next(d.begin()),8); //insert 8 at 2nd position
d.emplace(prev(d.end()),9); //insert 9 at 2nd last position


cout<<"Size of deque: "<<d.size()<<endl;


for(int value:d){
    cout<<value<<" ";
}
cout<<endl;


    return 0;
}