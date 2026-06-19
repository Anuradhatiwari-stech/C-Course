#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

class MiddleOfLL {
public:


    struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
        
    }
};

class LinkedList {
public:
    MiddleOfLL::ListNode* head;
  
    LinkedList() { head = nullptr; }

    void push_back(int value) {
        MiddleOfLL::ListNode* newNode = new MiddleOfLL::ListNode(value);

        if (!head) {
            head = newNode;
            return;
        }

        MiddleOfLL::ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printLL() {
        MiddleOfLL::ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


int main() {
    // Node* firstNode = new Node(10);
    // Node* secondNode = new Node(20);

    // firstNode->next = secondNode;

    LinkedList ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);

    ll.printLL();

    return 0;
}