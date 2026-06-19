#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;
 
class DetectCycleInLL {
public:

struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};

class LinkedList {
public:
    DetectCycleInLL::ListNode* head;
    LinkedList() { head = nullptr; }
    void push_back(int value) {
        DetectCycleInLL::ListNode* newNode = new DetectCycleInLL::ListNode(value);

        if (!head) {
            head = newNode;
            return;
        }

        DetectCycleInLL::ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printLL() {
        DetectCycleInLL::ListNode* temp = head;
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

    DetectCycleInLL detector;
    if (detector.hasCycle(ll.head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}
