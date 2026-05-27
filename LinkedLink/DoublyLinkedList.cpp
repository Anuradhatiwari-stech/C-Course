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
Node* prev;
Node(int x) : data(x), next(nullptr), prev(nullptr) {}


};

class DoublyLinkedList {
public:
Node* head;
Node* tail;
DoublyLinkedList() : head(nullptr), tail(nullptr) {}

void push_Front(int val){
Node* newNode = new Node(val);
if(head==nullptr){
head = newNode;
tail = newNode;
}else{
newNode->next = head;
head->prev = newNode;
head = newNode;
}
return;
}
void push_Back(int val){
Node* newNode = new Node(val);
if(head==nullptr){
head = newNode;
tail = newNode;
}else{
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
return;
}

void pop_Front(){
if(head==nullptr) return;
Node* temp = head;
if(head==tail){
head = nullptr;
tail = nullptr;
}else{
head = head->next;
head->prev = nullptr;
}
delete temp;
}
void pop_Back(){
if(head==nullptr) return;
Node* temp = tail;
if(head==tail){
head = nullptr;
tail = nullptr;
}else{
tail = tail->prev;tail->next = nullptr;
}
delete temp;
}

void printList(){
Node* temp = head;
while(temp){
cout << temp->data << " <-> ";
temp = temp->next;
}cout << "NULL" << endl;
}


// void insert(int x);
// void printList();
};
// void DoublyLinkedList::insert(int x) {
// Node* newNode = new Node(x);
// if (!head) {
// head = newNode;
// tail = newNode;
// return;
// }
// tail->next = newNode;
// newNode->prev = tail;
// tail = newNode;
// }
// void DoublyLinkedList::printList() {
// Node* temp = head;
// while (temp) {
// cout << temp->data << " <-> ";
// temp = temp->next;
// }cout << "NULL" << endl;
// }



int main() { 

DoublyLinkedList dll;
dll.push_Front(10);
dll.push_Front(20);
dll.push_Front(30);
dll.push_Back(40);
dll.push_Back(50);
dll.pop_Front();
dll.pop_Back();

dll.printList();


    return 0;
}