//
//  SinglyLinkedList.h
//  Data Structure Implementations
//
//  Created by user on 4/6/23.
//

#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

#include <iostream>
using namespace std;

// All struct is public by default.
struct Node
{
    // Constructor
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// print the linkedlist (help check)
void listDisplay(const Node* head)
{
    const Node* cursor = head;
    while (cursor != nullptr)
    {
        cout << cursor->data << ' ';
        cursor = cursor->next;
    }
    cout << endl;
}

// creates new Node with data val at front; returns new head
Node* insertAtFront(Node* head, int val)
{
    // Create a node for the data, make the new node point to the head, and make the head point to the address of the new node.
    Node* head = new Node(data, head);
    return head
}

// creates new Node with data val at end
void insertAtBack(Node*& head, int val)
{
    // Create a new node when there is no linkedlist
    if (head == nullptr)
    {
       Node* head = new Node(val);
    }
    else
    {
        Node* last = head;
        //loop untill next of trail
        while (last->next)
        {
            last = last->next;
        }
        // if next node is nullptr, add a new node
        last->next = new Node(val);
    }
}

// creates new Node with data val after Node loc
void insertAfter(Node* head, int val, Node*& loc)
{
    if (head == nullptr || loc == nullptr)
    {
        return;
    }
    // new node which have rest of loc have
    Node* newNode = new Node(val,loc->next);
    loc->next = newNode;
}

// removes first Node; returns new head
Node* deleteFront(Node* head)
    if (head == nullptr)
    {
        return nullptr;
    }
    // store next
    Node* newHead = head->next;
    
    // Remove the first node --- delete pointer
    delete head;
    head = nullptr;
    
    //return
    return newHead
}

// removes last Node
void deleteBack(Node*& head)
{
    // No linkedlist here
    if (head == nullptr){
        return;
    }
    // only have 1 node
    else if (head->next = nullptr){
        delete head;
        head == nullptr;
        return;
    }
    // serval nodes
    else {
        // create a cursor to traverse
        Node* cursor =  head;
        
        // loop over the linkedlist
        while(cursor->next->next != nullptr){
            cursor = cursor->next;
        }
        
        // delete back
        delete cursor->next;
        cursor->next = nullptr;
    }
}

// deletes Node loc; returns head
Node* deleteNode(Node* head, Node* loc)
{
    // no linkedlist here
    if (head == nullptr)
    {
        return nullptr;
    }
    
    // call delete front
    else if (head == loc)
    {
        deleteFront(Node* head);
    }
    else {
        Node* prev = head;
        Node* current = head->next;
        // loop until current node is trail
        while (current != nullptr)
        {
            // find the location
            if(current == loc)
            {
                // isolate this node
                prev->next = current->next;
                delete current;
                current = nullptr;
                return head;
            }
            current = current->next;
        }
    }
    return head;
}

// returns length of the list
int listLength(const Node* head)
{
    int count = 0;
    // make a copy of head, and loop to until trail
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}

// reverses the linked list iteratively
Node* reverseIterative(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
        
    // prev,currsor,next
    Node* prev =  nullptr;
    Node* curssor = head;
    Node* next =  nullptr;
    
    // loop until cursor reach the trail
    while (currsor != nullptr)
    {
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
        next = cursor->next;
        cursor->next = prev;
        prev = currsor;
        current = next;
    }
    return prev;
}

// reverses the linked list recursively
Node* reverseRecursive(Node* head)


#endif /* SinglyLinkedList_h */
