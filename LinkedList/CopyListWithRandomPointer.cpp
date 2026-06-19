#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(NULL), random(NULL) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(NULL) {}
    void insert(int x);
    void printList();
    void printRandomList();
    LinkedList* copyListWithRandomPointer();
};

void LinkedList::insert(int x) {
    Node* newNode = new Node(x);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void LinkedList::printRandomList() {
    Node* temp = head;
    while (temp) {
        if (temp->random)
            cout << "Node " << temp->val << " random points to " << temp->random->val << endl;
        else
            cout << "Node " << temp->val << " random points to NULL" << endl;
        temp = temp->next;
    }
}
LinkedList* LinkedList::copyListWithRandomPointer() {
    if (!head) return nullptr;

    // Step 1: Create new nodes and insert them next to original nodes
    Node* curr = head;
    while (curr) {
        Node* newNode = new Node(curr->val);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // Step 2: Assign random pointers for the copied nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Separate the original and copied lists
    curr = head;
    Node* copiedHead = head->next;
    Node* copyCurr = copiedHead;

    while (curr) {
        curr->next = curr->next->next;
        if (copyCurr->next) {
            copyCurr->next = copyCurr->next->next;
        }
        curr = curr->next;
        copyCurr = copyCurr->next;
    }

    LinkedList* copiedList = new LinkedList();
    copiedList->head = copiedHead;
    return copiedList;
}

int main() {
    LinkedList originalList;
    originalList.insert(1);
    originalList.insert(2);
    originalList.insert(3);

    // Setting up random pointers
    originalList.head->random = originalList.head->next->next; // 1 -> 3
    originalList.head->next->random = originalList.head;       // 2 -> 1
    originalList.head->next->next->random = originalList.head->next; // 3 -> 2

    cout << "Original List:" << endl;
    originalList.printList();
    originalList.printRandomList();

    LinkedList* copiedList = originalList.copyListWithRandomPointer();

    cout << "\nCopied List:" << endl;
    copiedList->printList();
    copiedList->printRandomList();

    return 0;
}

