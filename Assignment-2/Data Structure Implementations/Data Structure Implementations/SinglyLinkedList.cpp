//
//  SinglyLinkedList.cpp
//  Data Structure Implementations
//
//  Created by user on 4/9/23.
//

#include "SinglyLinkedList.h"

// destructor
SinglyLinkedList::~SinglyLinkedList() {
    Node* currsor = head;
    while (currsor != nullptr) {
        Node* temp = currsor->next;
        delete currsor;
        // prevent dangling pointer
        currsor = nullptr;
        currsor = temp;
    }
}

// print the linkedlist (help check)
void SinglyLinkedList::listDisplay()
{
    const Node* cursor = head;
    while (cursor != trail)
    {
        cout << cursor->data << ' ';
        cursor = cursor->next;
    }
    cout << endl;
}

// insert a new node with data val at the front of the list
SinglyLinkedList::Node* SinglyLinkedList::insertAtFront(int val) {
    // create a new head, and set old head as next of new head
    Node* newNode = new Node{ val, head };
    head = newNode;
    return head;
}

// insert a new node with data val at the back of the list
void SinglyLinkedList::insertAtBack(int val) {
    Node* newNode = new Node{ val, nullptr };
    // new Node, if null
    if (head == nullptr) {
        head = newNode;
    }
    // loop until back and link a new node
    else {
        Node* currsor = head;
        while (currsor->next != nullptr) {
            currsor = currsor->next;
        }
        currsor->next = newNode;
    }
}

// insert a new node with data val after node loc
void SinglyLinkedList::insertAfter(int val, Node*& loc) {
   // edge case
    if (loc == nullptr) {
        return;
    }
    Node* newNode = new Node{ val, loc->next };
    loc->next = newNode;
}

// delete the first node in the list
SinglyLinkedList::Node* SinglyLinkedList::deleteFront() {
    // null
    if (head == nullptr) {
        return nullptr;
    }
    // isolate head
    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    
    delete temp;
    temp = nullptr;
    return head;
}

// delete the last node in the list
void SinglyLinkedList::deleteBack() {
    if (head == nullptr) {
        return;
    }
    // if only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    // loop until end, and delete it
    Node* currsor = head;
    while (currsor->next->next != nullptr) {
        currsor = currsor->next;
    }
    delete currsor->next;
    currsor->next = nullptr;
}

// delete node loc from the list
SinglyLinkedList::Node* SinglyLinkedList::deleteNode(Node* loc) {
    if (head == nullptr || loc == nullptr) {
        return nullptr;
    }
    // delete head
    if (loc == head) {
        deleteFront();
    }
    
    // loop to loc,
    Node* currsor = head;
    while (currsor->next != loc && currsor != nullptr) {
        currsor = currsor->next;
    }
    // isolate the node and delete
    currsor->next = loc->next;
    delete loc;
    return head;
}

// return the length of the list
int SinglyLinkedList::length()const {
    int len = 0;
    Node* currsor = head;
    while (currsor != nullptr) {
        len++;
        currsor = currsor->next;
    }
    return len;
}

// Reverse the SinglyLinkedList by iterative
void SinglyLinkedList::reverseIterative() {
    if (head == nullptr || head->next == nullptr) {
        // empty or single node list
        return;
    }
    
    Node* prev = nullptr;
    Node* currsor = head;
    Node* next = nullptr;
    
    /*
    C
    1 2 3 4 5
    C P
    1 2 3 4 5
    P C
    2 1 3 4 5
    C   P
    2 1 3 4 5
     */
    
    while (currsor != nullptr) {
        next = currsor->next;
        currsor->next = prev;
        prev = currsor;
        currsor = next;
    }
    
    head = prev;
}

void SinglyLinkedList::reverseRecursive() {
    // Use a helper function to do the recursion and get the new head.
    head = reverseRecursivehelper(head);
}

// Reverse the SinglyLinkedList by recursive
SinglyLinkedList::Node* SinglyLinkedList::reverseRecursivehelper(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        // Base case: the list is empty or has only one node
        return node;
    }
    else {
        // Recursive case: reverse the sublist starting from the second node
        Node* new_head = reverseRecursivehelper(node->next);
        node->next->next = node;
        node->next = nullptr;
        return new_head;
    }
}
