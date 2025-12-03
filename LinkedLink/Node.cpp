#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Node {
public:
    int data;
    Node* next; 

    Node(int val) {
        data = val;
        next = nullptr;
    }

};

class LinkedList {
Node* head;
Node* tail;
public:
    
    LinkedList() {
        head = tail = nullptr;
    }
};

int main() {
    Node* firstNode = new Node(10);
    Node* secondNode = new Node(20);

    firstNode->next = secondNode;

    cout << "First Node Data: " << firstNode->data << endl;
    cout << "Second Node Data: " << firstNode->next->data << endl;

    return 0;
}