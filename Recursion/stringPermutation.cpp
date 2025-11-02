#include <iostream>
#include <vector>
using namespace std;

void permutationsOfString(string str, int index) {
    // Base case: if the current index is at the end of the string
    if (index == str.length()) {
        cout << str << endl; // Print the current permutation
        return;
    }
    for (int i = index; i < str.length(); i++) {
        swap(str[index], str[i]); // Swap to create a new permutation
        permutationsOfString(str, index + 1); // Recurse for the next index
        swap(str[index], str[i]); // Backtrack to restore the original string
    }
}

int main() {
    string str = "ABC";
    cout << "All permutations of the given string are:" << endl;
    permutationsOfString(str, 0);
    return 0;
}