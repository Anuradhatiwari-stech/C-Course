#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

class IsPalindrome {
public:

    struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* previous = NULL;
        ListNode* current = slow;
        ListNode* next = NULL;

        while(current != NULL){
            next = current->next;
            current->next = previous;

            previous = current;
            current = next;
        }

        ListNode* left = head;
        ListNode* right = previous;

        while(right != NULL){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true; 
    }
};

class LinkedList {
public:
    IsPalindrome::ListNode* head;
    LinkedList() { head = nullptr; }    
    void push_back(int value) {
        IsPalindrome::ListNode* newNode = new IsPalindrome::ListNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        IsPalindrome::ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printLL() {
        IsPalindrome::ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);

    cout << "Original List: ";
    ll.printLL();
    IsPalindrome palindromeChecker;
    bool result = palindromeChecker.isPalindrome(ll.head);
    if(result){
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}