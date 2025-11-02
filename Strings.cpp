#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


int main() {
    string str1 = "Hello"; //dinamic size
    string str2 = "World!"; //dinamic size
    string str = str1 + " " + str2; // Concatenation
    cout << "Concatenated String: " << str << endl;
    cout << (str1 < str2) << endl; // Comparison
    cout << "Length of str1: " << str1.length() << endl; // Length
    tolower(str1[0]); // Access and modify character
    cout << "Is str1 a palindrome? " << (isPalindrome(str1) ? "Yes" : "No") << endl; // Palindrome check

    for(int i=0;i<str.length();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    
    // // Convert to uppercase
    // transform(str.begin(), str.end(), str.begin(), ::toupper);
    // cout << "Uppercase: " << str << endl;
    
    // // Convert to lowercase
    // transform(str.begin(), str.end(), str.begin(), ::tolower);
    // cout << "Lowercase: " << str << endl;
    
    // // Reverse the string
    reverse(str.begin(), str.end());
    cout << "Reversed: " << str << endl;
    
    // // Find a substring
    // string toFind = "world";
    // size_t found = str.find(toFind);
    // if (found != string::npos) {
    //     cout << "'" << toFind << "' found at index: " << found << endl;
    // } else {
    //     cout << "'" << toFind << "' not found" << endl;
    // }
    
    // // Replace a substring
    // string toReplace = "WORLD";
    // string replacement = "C++";
    // found = str.find(toReplace);
    // if (found != string::npos) {
    //     str.replace(found, toReplace.length(), replacement);
    //     cout << "After replacement: " << str << endl;
    // } else {
    //     cout << "'" << toReplace << "' not found for replacement" << endl;
    // }
    
    return 0;
}   