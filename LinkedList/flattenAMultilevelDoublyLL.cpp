#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

class FlattenAMultilevelDoublyLL {
public: 

    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node* child;
        Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
    };

    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* current = head;

        while (current) {
            if (current->child) {
                Node* childHead = flatten(current->child);
                Node* childTail = childHead;

                while (childTail->next) {
                    childTail = childTail->next;
                }

                if (current->next) {
                    current->next->prev = childTail;
                    childTail->next = current->next;
                }

                current->next = childHead;
                childHead->prev = current;
                current->child = nullptr; // Don't forget to set the child pointer to null
            }
            current = current->next;
        }

        return head;
    }
};

class LinkedList {
public:
    FlattenAMultilevelDoublyLL::Node* head;
    LinkedList() { head = nullptr; }
    void push_back(int value) {
        FlattenAMultilevelDoublyLL::Node* newNode = new FlattenAMultilevelDoublyLL::Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        FlattenAMultilevelDoublyLL::Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void printLL() {
        FlattenAMultilevelDoublyLL::Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};




int main(){
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.printLL();


    return 0;
}