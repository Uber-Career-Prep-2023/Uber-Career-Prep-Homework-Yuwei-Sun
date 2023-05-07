//
//  DoublyLinkedList.cpp
//  Data Structure Implementations
//
//  Created by user on 4/24/23.
//

#include <stdio.h>
#include <iostream>
using namespace std;

namespace DoublyLinkedList {
    struct Node {
        // constructor
        Node(int val,Node* prev=nullptr,Node* next=nullptr) : data(val), prev(prev), next(next) {}
        int data;
        Node* prev;
        Node* next;
    };

    class DoublyLinkedList {
    private:
        Node* head;
        Node* trail;
        int size;
        // helper function for reverseRecursive
        Node* reverseRecursiveHelper(Node* node) {
                if (node->next == nullptr) {
                    // Base case: last node in the list
                    return node;
                } else {
                    // Recursive case
                    Node* newHead = reverseRecursiveHelper(node->next);
                    // Reverse the links
                    node->next->next = node;
                    node->prev = node->next;
                    node->next = nullptr;
                    return newHead;
                }
            }

    public:
        DoublyLinkedList() {
            head = nullptr;
            trail = nullptr;
            size = 0;
        }
        
        // print the linkedlist (help check)
        void listDisplay()
        {
            const Node* cursor = head;
            while (cursor != trail)
            {
                cout << cursor->data << ' ';
                cursor = cursor->next;
            }
            cout << endl;
        }
        
        // creates new Node with data val at front; returns new head
        Node* insertAtFront(int val)
        {
           // create a newhead by val. The next of this newhead is current head. And prev is nullptr.
            Node* newHead = new Node(val,nullptr,head);
            size++;
            return newHead;
        }

        // creates new Node with data val at end
        void insertAtBack(int val)
        {
            // Create a new node when there is no linkedlist
            if (head == nullptr)
            {
                head = new Node(val);
                size++;
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
                size++;
            }
        }

        // creates new Node with data val after Node loc
        void insertAfter(int val, Node*& loc)
        {
            if (head == nullptr || loc == nullptr)
            {
                return;
            }
            // new node which have rest of loc have
            Node* newNode = new Node(val,loc,loc->next);
            loc->next = newNode;
            size++;
        }
        
        // removes first Node; returns new head
        Node* deleteFront()
        {
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
            size--;
            
            //return
            return newHead;
        }

        // removes last Node
        void deleteBack()
        {
            // No linkedlist here
            if (head == nullptr){
                return;
            }
            // only have 1 node
            else if (head->next == nullptr){
                delete head;
                head = nullptr;
                size = 0;
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
                size--;
            }
        }

        // deletes Node loc; returns head
        Node* deleteNode(Node* loc)
        {
            // no linkedlist here
            if (head == nullptr)
            {
                return nullptr;
            }
            
            // call delete front
            else if (head == loc)
            {
                deleteFront();
                size = 0;
            }
            else {
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
                        size--;
                        return head;
                    }
                    current = current->next;
                }
            }
            return head;
        }

        // returns length of the list
        int listLength()
        {
            return size;
        }
        
        // reverses the linked list iteratively
        Node* reverseIterative()
        {
            if (head == nullptr || head->next == nullptr)
            {
                return nullptr;
            }
            // prev,currsor,next
            Node* temp =  nullptr;
            Node* cursor = head;
            Node* next = nullptr;
            
            // loop until cursor reach the trail
            while (cursor != nullptr)
            {
                next = cursor->next;
                temp = cursor->prev;
                cursor->prev = cursor->next;
                cursor->next = temp;
                cursor = next;
            }
            return temp;
        }
        
        // reverses the linked list recursively (Hint: you will need a helper function)
        Node* reverseRecursive() {
            if (head == nullptr || head->next == nullptr) {
                // Base case: empty list or list with only one node
                return head;
            } else {
                // Recursive case
                Node* newHead = reverseRecursiveHelper(head);
                // Update the tail to be the old head (which is now the tail)
                trail = head;
                trail->next = nullptr;
                // Update the head to be the new head
                head = newHead;
                head->prev = nullptr;
                return head;
            }
        }

    };
}
