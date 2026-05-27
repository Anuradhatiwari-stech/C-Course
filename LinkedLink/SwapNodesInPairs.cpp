#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

class SwapNodesInPairs {
public:
    struct Node {
       int val;
       Node *next;
       Node() : val(0), next(nullptr) {}
       Node(int x) : val(x), next(nullptr) {}
       Node(int x, Node *next) : val(x), next(next) {}
    };

Node* swapPairs(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* first = head;
    Node* second = head->next;

    first->next = swapPairs(second->next);
    second->next = first;

    return second; 
}
};

class LinkedList {
public:    SwapNodesInPairs::Node* head;
    LinkedList() { head = nullptr; }

    void push_back(int value) {
        SwapNodesInPairs::Node* newNode = new SwapNodesInPairs::Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        SwapNodesInPairs::Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void printList() {
        SwapNodesInPairs::Node* temp = head;
        while(temp != nullptr){
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

    cout << "Original List: ";
    list.printList();

    SwapNodesInPairs swapper;
    list.head = swapper.swapPairs(list.head);

    cout << "Swapped List: ";
    list.printList();

    return 0;
}

