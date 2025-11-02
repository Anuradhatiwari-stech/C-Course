#include <iostream>
#include <vector>
using namespace std;



int main() {
    vector<int>vec = {1,2,3,4,5};
    // vector<int>::reverse_iterator itr;
     for(auto itr=vec.begin(); itr!=vec.end(); itr++){
         cout<<*itr<<" ";
        }
    cout<<endl;
    // vector<int>vec2(vec1); //size=4, initial value=20
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);
    // vec.push_back(5);
    // vec.pop_back();
    // vec.emplace_back(6); //faster than push_back
    // vec.erase(vec.begin()); //erase element at index 1
    // vec.insert(vec.begin()+5,6); //insert 6 at index 5
    // vec.clear(); //clear the vector
    // vec.empty(); //check if vector is empty or not

    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;

    cout<<"vec.begin:"<<*(vec.begin())<<endl;
    cout<<"vec.end:"<<(*vec.end())<<endl;
    // cout<<vec.capacity()<<endl; //capacity is double of size
    // cout<<"value at idx 2:" << vec[2]<< "or" << vec.at(3) <<endl;
    
    // cout<<"first value:" << vec.front()<<endl;
    // cout<<"last value:" << vec.back()<<endl;

    
   
    return 0;
}