#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;


class AddTwoNumbersinLL {
    public:
    struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummyHead->next; // Return the head of the new linked list
    }
};

class LinkedList {
public:
    AddTwoNumbersinLL::ListNode* head;
    LinkedList() { head = nullptr; }
    void push_back(int value) {
        AddTwoNumbersinLL::ListNode* newNode = new AddTwoNumbersinLL::ListNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        AddTwoNumbersinLL::ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }   

    void printLL() {
        AddTwoNumbersinLL::ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


int main(){
    LinkedList ll1;
    ll1.push_back(6);
    ll1.push_back(4);
    ll1.push_back(3);   
    cout << "First List: ";
    ll1.printLL();
    LinkedList ll2;
    ll2.push_back(3);
    ll2.push_back(6);
    ll2.push_back(4);
    cout << "Second List: ";
    ll2.printLL();
    AddTwoNumbersinLL adder;
    LinkedList result;
    result.head = adder.addTwoNumbers(ll1.head, ll2.head);
    cout << "Resultant List after adding: ";
    result.printLL();


    return 0;
}