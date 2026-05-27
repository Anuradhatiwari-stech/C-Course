#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;


class ReverseALL {
    public:

    // ReverseALL() {}

    struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* reverseList(ListNode* head) {


        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* next = NULL;

        while(current != NULL){
            next = current->next;
            current->next = previous;

            previous = current;
            current = next;
        }

        return previous;
        
    }


    
};

class LinkedList {
public:
    ReverseALL::ListNode* head;
  
    LinkedList() { head = nullptr; }

    void push_back(int value) {
        ReverseALL::ListNode* newNode = new ReverseALL::ListNode(value);

        if (!head) {
            head = newNode;
            return;
        }

        ReverseALL::ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printLL() {
        ReverseALL::ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }


};


int main() {
    
    LinkedList ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);

    cout << "Original List: ";
    ll.printLL();

    ReverseALL reverser;
    ll.head = reverser.reverseList(ll.head);   // Update the head of the linked list to the new head returned by reverseList

    cout << "Reversed List: ";
    ll.printLL();

    return 0;
}