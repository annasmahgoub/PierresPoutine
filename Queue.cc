#include "Queue.h"

Queue::Queue() 
    : head(NULL), tail(NULL), numOrders(0) {
}

Queue::~Queue() {
    Node* curr = head;
    Node* prev;

    while(curr != nullptr) {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}

bool Queue::empty() const {
    if (numOrders == 0) {return true;} 
    return false;
}

int Queue::size() const {
    return numOrders;
}

Order *Queue::peekFirst() const {
    if (empty()) {return nullptr;}
    return head->data;
}

Order *Queue::popFirst() {
    if (empty()) {return nullptr;} // check if linked list is empty

    Order* order = head->data; // data to be returned
    Node* temp = head; 
    head = head->next; // set new head to next Node after head
    delete temp; 

    numOrders--; // decrement linked list size

    if(empty()) {tail = NULL;} // check if linked lsit is empty
    return order; 
}

void Queue::addLast(Order *order) {
    Node* node = new Node;
    node->next = nullptr;
    node->data = order;

    if (empty()) {
        head = node;
        tail = node;
    }else {
        Node* temp = tail;
        temp->next = node;
        tail = node;
    }

    numOrders++; // increment size of linked list
}