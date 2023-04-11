//
//  SinglyLinkedList.h
//  Data Structure Implementations
//
//  Created by user on 4/6/23.
//

#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h
#include <stdio.h>

#include <iostream>
using namespace std;


class SinglyLinkedList {
    
public:
    // next and data need to be accessed
    struct Node
    {
        // Node constructor
        Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
        int data;
        Node* next;
    };
    // constructor
    SinglyLinkedList() : head(nullptr), trail(nullptr) {}
    // deconstructor
    ~SinglyLinkedList();
    
    void listDisplay(const Node* head);
    Node* insertAtFront(int val);
    void insertAtBack(int val);
    void insertAfter(int val, Node*& loc);
    Node* deleteFront();
    void deleteBack();
    Node* deleteNode(Node* loc);
    int length() const;
    Node* reverseIterative();
    Node* reverseRecursive();
    
private:
    Node* head;
    Node* trail;
};

#endif /* SinglyLinkedList_h */
