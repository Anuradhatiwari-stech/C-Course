#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

class ReverseBetween {
public:
    struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* current = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* next = current->next;
            current->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};

class LinkedList {
public:    ReverseBetween::ListNode* head;
    LinkedList() { head = nullptr; }
    void push_back(int value) {
        ReverseBetween::ListNode* newNode = new ReverseBetween::ListNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        ReverseBetween::ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void printLL() {
        ReverseBetween::ListNode* temp = head;
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
    ll.push_back(4);
    ll.push_back(5);
    
    
    
    ReverseBetween rb;
    ll.head = rb.reverseBetween(ll.head, 2, 4);

    cout << "Reversed List: ";
    ll.printLL();

    return 0;
}