#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main(){
list<int>l;
l.push_back(1);
l.push_back(2);
l.push_front(3);
l.push_front(4);
l.emplace_back(5);
l.emplace_front(6);
l.pop_back();
l.pop_front();
l.remove(2); //remove all occurrences of 2
l.emplace(l.begin(),7); //insert 7 at beginning
l.emplace(next(l.begin()),8); //insert 8 at 2nd position
l.emplace(prev(l.end()),9); //insert 9 at 2nd last position
l.sort(); //sort the list
l.reverse(); //reverse the list
cout<<"Size of list: "<<l.size()<<endl;


for(int value:l){
    cout<<value<<" ";
}
cout<<endl;


    return 0;
}