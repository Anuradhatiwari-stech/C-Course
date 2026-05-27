#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

class Merge2SortedListInLL {
public:

struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class LinkedList {
public:
    Merge2SortedListInLL::ListNode* head;
    LinkedList() { head = nullptr; }
    void push_back(int value) {
        Merge2SortedListInLL::ListNode* newNode = new Merge2SortedListInLL::ListNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        Merge2SortedListInLL::ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printLL() {
        Merge2SortedListInLL::ListNode* temp = head;
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
    ll.push_back(4);

    LinkedList ll2;
    ll2.push_back(1);
    ll2.push_back(3);
    ll2.push_back(4);

    Merge2SortedListInLL merger;
    Merge2SortedListInLL::ListNode* mergedHead = merger.mergeTwoLists(ll.head, ll2.head);

    cout << "Merged Linked List: ";
    while (mergedHead != nullptr) {
        cout << mergedHead->val << " -> ";
        mergedHead = mergedHead->next;
    }
    cout << "NULL" << endl;

    return 0;
}