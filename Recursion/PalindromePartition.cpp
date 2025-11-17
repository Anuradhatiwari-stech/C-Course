#include <iostream>
#include <vector>
#include <set>
using namespace std;


// void getAllPalindromicPartitions(int idx, const string& str, vector<string>& currentPartition, vector<vector<string>>& allPartitions) {
//     // Base case: if we have reached the end of the string
//     if (idx == str.size()) {
//         allPartitions.push_back(currentPartition);
//         return;
//     }
//     // Explore all possible substrings starting from idx
//     for (int len = 1; len <= str.size() - idx; len++) {
//         string substring = str.substr(idx, len);
//         // Check if the substring is a palindrome
//         string revSubstring = substring;
//         reverse(revSubstring.begin(), revSubstring.end());
//         if (substring == revSubstring) {
//             // If it is a palindrome, include it in the current partition
//             currentPartition.push_back(substring);
//             // Recur for the remaining substring
//             getAllPalindromicPartitions(idx + len, str, currentPartition, allPartitions);
//             // Backtrack: remove the last added substring
//             currentPartition.pop_back();
//         }
//     }
// }
// vector<vector<string>> palindromePartitioning(const string& str) {
//     vector<vector<string>> allPartitions;
//     vector<string> currentPartition;
//     getAllPalindromicPartitions(0, str, currentPartition, allPartitions);
//     return allPartitions;
// }

bool isPalindrome(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s2 == s;
    }
    void getAllPalindromicPartitions(string s,vector<string> &currentPartition,
                                     vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(currentPartition);
            return;
        }
        for(int i=0; i<s.size(); i++){
            string part = s.substr(0,i+1);
            if(isPalindrome(part)){
                currentPartition.push_back(part);
                getAllPalindromicPartitions(s.substr(i+1),currentPartition,ans);
                currentPartition.pop_back();
            }
        }
    }
                                     

    vector<vector<string>> palindromePartitioning(string s) {
    vector<vector<string>> ans;
    vector<string> currentPartition;
    getAllPalindromicPartitions(s, currentPartition, ans);
    return ans;
    }



int main() {
    string str = "aab";
    vector<vector<string>> result = palindromePartitioning(str);
    cout << "All palindromic partitions of the string \"" << str << "\":\n";
    for (const auto& partition : result) {
        cout << "[ ";
        for (const auto& substr : partition) {
            cout << "\"" << substr << "\" ";
        }
        cout << "]\n";
    }
    return 0;
}