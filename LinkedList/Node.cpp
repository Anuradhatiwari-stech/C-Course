#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
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
    
    void push_front(int val) {
      Node* newNode = new Node(val);
      if(head == nullptr) {
         head = tail = newNode;
         return;
      }else {
          tail->next = newNode;
          tail = newNode;
      }
   }

   void push_back(int val) {
      Node* newNode = new Node(val);
      if(head == nullptr) {
         head = tail = newNode;
         return;
      }else {
          tail->next = newNode;
          tail = newNode;
      }
   }

   void pop_front() {
       if(head == nullptr) {
           cout << " Linked List is empty "<< endl;
           return;
       }else {
           Node* temp = head;
           head = head->next;
           temp->next = nullptr;
           delete temp;
       }
   }

   void pop_back() {
       if(head == nullptr) {
           cout << " Linked List is empty "<< endl;
           return;
       }else {
           Node* temp = head;
           while(temp->next != tail) {
               temp = temp->next;
           }
           Node* toDelete = tail;
           tail = temp;
           tail->next = nullptr;
           delete toDelete;
       }
   }

   void insertAtPosition(int pos, int val) {
       // Implementation for inserting at a specific position
       if(pos < 0) {
           cout << "Invalid Position" << endl;
           return;
       }
       if(pos == 0) {
           push_front(val);
           return;
       }
        
            Node* temp = head;
            for(int i = 0; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;

            }
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            if(temp == nullptr) {
                cout << "Position out of bounds" << endl;
                delete newNode;
                return;
            }
   }

   int search(int val) {
       Node* temp = head;
       int pos = 0;
       while(temp != nullptr) {
           if(temp->data == val) {
               return pos;
           }
           temp = temp->next;
           pos++;
       }
       return -1; // Not found
   }

    void printLL() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout<<"NULL"<< endl;
    }
}; 

int main() {
    // Node* firstNode = new Node(10);
    // Node* secondNode = new Node(20);

    // firstNode->next = secondNode;
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_back(30);
    ll.push_back(40);
    // ll.pop_front();
    // ll.pop_back();  
    ll.insertAtPosition(1, 25);

    ll.printLL();

    cout << "Position of 30: " << ll.search(30) << endl;


    // cout << "First Node Data: " << firstNode->data << endl;
    // cout << "Second Node Data: " << firstNode->next->data << endl;

    return 0;
}