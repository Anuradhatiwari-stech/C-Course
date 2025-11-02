#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
using namespace std;


int main(){
stack<int>s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);

stack<int> s2;
s2.swap(s); //swaps contents of s and s2

cout<<"Size of stack1: "<<s.size()<<endl;
cout<<"Size of stack2: "<<s2.size()<<endl;

// while(!s.empty()){
//     cout<<s.top()<<" ";
//     s.pop();
// }
// cout <<endl;

    return 0;
}