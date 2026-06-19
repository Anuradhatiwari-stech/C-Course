#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;


class DetectNRemoveCycleInLL {
public:

struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *detectCycle(ListNode *head) {

        if(head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            }

            
        }

        if(!isCycle){
            return NULL;
        }

        slow = head;
        ListNode* prev = nullptr;

        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = nullptr;
        return slow;

    }
};

// class LinkedList {
// public:
//     DetectNRemoveCycleInLL::ListNode* head;
//     LinkedList() { head = nullptr; }
//     void push_back(int value) {
//         DetectNRemoveCycleInLL::ListNode* newNode = new DetectNRemoveCycleInLL::ListNode(value);

//     }
// };

class LinkedList {
public:
    DetectNRemoveCycleInLL::ListNode* head;
    LinkedList() { head = nullptr; }
    void push_back(int value) {
        DetectNRemoveCycleInLL::ListNode* newNode = new DetectNRemoveCycleInLL::ListNode(value);

        if (!head) {
            head = newNode;
            return;
        }

        DetectNRemoveCycleInLL::ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printLL() {
        DetectNRemoveCycleInLL::ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(0);
    ll.push_back(-4);

    // Creating a cycle for testing
    ll.head->next->next->next->next = ll.head->next; // -4 points to 2

    DetectNRemoveCycleInLL detector;
    DetectNRemoveCycleInLL::ListNode* cycleStartNode = detector.detectCycle(ll.head);
    if (cycleStartNode) {
        cout << "Cycle detected at node with value: " << cycleStartNode->val << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}