//
//  DoublyLinkedList .h
//  Data Structure Implementations
//
//  Created by user on 4/7/23.
//

#ifndef DoublyLinkedList__h
#define DoublyLinkedList__h

#include <iostream>
using namespace std;

struct Node {
    // constructor
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    int data;
    Node* prev;
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
   // create a newhead by val. The next of this newhead is current head. And prev is nullptr.
    Node* newHead = new Node(val,nullptr,head);
    return newHead;
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
        last->next = new Node(val,last,nullptr);
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
    Node* newNode = new Node(val,loc,loc->next);
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
    newHead->prev = nullptr;
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
        cursor->prev = nullptr;
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
                current->prev->next = current->next;
                if (current->next != nullptr)
                   {
                    current->next->prev = current->prev;
                   }
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
    Node* temp =  nullptr;
    Node* curssor = head;
    
    // loop until cursor reach the trail
    while (currsor != nullptr)
    {
        next = curssor->next;
        temp = curssor->prev;
        curssor->prev = curssor->next;
        curssor->next = temp;
        currssor = next;
    }
    return temp;
}

// reverses the linked list recursively (Hint: you will need a helper function)
Node* reverseRecursive(Node* head)
{
    
}

#endif /* DoublyLinkedList__h */
