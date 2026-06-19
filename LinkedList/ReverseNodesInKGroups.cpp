#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

class ReverseNodesInKGroups {
public:
    struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}

    };   
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k <= 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* previous = dummy;
        ListNode* current = head;
        ListNode* next = NULL;

        while(current != NULL){
            ListNode* tail = current;
            int count = 0;

            while(count < k && tail != NULL){
                tail = tail->next;
                count++;
            }

            if(count == k){
                next = tail;

                ListNode* prev = next;
                ListNode* curr = current;

                for(int i = 0; i < k; i++){
                    ListNode* temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                }

                previous->next = prev;
                previous = current;
                current = next;
            } else {
                break;
            }
        }

        return dummy->next; 
    }
};

class LinkedList {
public:    ReverseNodesInKGroups::ListNode* head;
    LinkedList() { head = nullptr; }

    void push_back(int value) {
        ReverseNodesInKGroups::ListNode* newNode = new ReverseNodesInKGroups::ListNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        ReverseNodesInKGroups::ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList() {
        ReverseNodesInKGroups::ListNode* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    cout << "Original List: ";
    list.printList();

    ReverseNodesInKGroups solution;
    int k = 3;
    list.head = solution.reverseKGroup(list.head, k);

    cout << "Reversed in groups of " << k << ": ";
    list.printList();

    return 0;
}


