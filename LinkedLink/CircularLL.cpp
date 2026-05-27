#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList{
public:
    Node* head;
    CircularLinkedList(){
        head = nullptr;
    }
    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            head->next = head; // Point to itself to make it circular
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Point back to head to maintain circular structure
    }
    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            head->next = head; // Point to itself to make it circular
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Point back to head to maintain circular structure
    }

    void deleteAtHead(){
        if(head == nullptr) return;
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        Node* toDelete = head;
        temp->next = head->next; // Point last node to the new head
        head = head->next; // Move head to the next node
        delete toDelete; // Delete the old head
    }

    void deleteAtTail(){
        if(head == nullptr) return;
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        Node* toDelete = temp->next; // Last node
        temp->next = head; // Point second last node to head
        delete toDelete; // Delete the old tail
    }

    void printList(){
        if(head == nullptr) return; 
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(back to head)" << endl;

    }
};


int main(){
    CircularLinkedList cll;
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtTail(3);
    cll.insertAtTail(4);
    cll.printList();
    cll.deleteAtHead();
    cll.printList();
    cll.deleteAtTail();
    cll.printList();
    
    return 0;
}