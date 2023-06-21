//
//  Queue.cpp
//  Data Structure Implementations
//
//  Created by user on 4/9/23.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Queue
{
public:
    // constructor
    Queue(): head(nullptr),trail(nullptr){}
    // destructor
    ~Queue();
    // returns a boolean indicating whether the queue is empty
    bool isQueueEmpty() const;
    // returns the first item in the queue
    int peek() const;
    // adds x to the back of the queue
    void enqueue(int x);
    // removes and returns the first item in the queue
    int dequeue();
    
    
private:
    struct Node
    {
        int data;
        Node* next;
    };
    // begin of queue and end of queue
    Node* head;
    Node* trail;
};

Queue::~Queue()
{
    Node* cursor = head;
    // traverse + delete
    while (cursor != nullptr)
    {
        Node* next = cursor->next;
        delete cursor;
        cursor = nullptr;
        cursor = next;
    }
}

// returns a boolean indicating whether the queue is empty
bool Queue::isQueueEmpty() const
{
    return head==nullptr;
}

// returns the first item in the queue
int Queue::peek() const
{
    // empty queue
    if (isQueueEmpty())
    {
        return -1;
    }
    else
    {
        return head->data;
    }
}

// adds x to the back of the queue
void Queue::enqueue(int x)
{
    Node* newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;
        
        // If queue is empty, make new node as head and tail both
        if (isQueueEmpty())
        {
            head = newNode;
            trail = newNode;
        }
        else
        {
            // Else, put the new node at the end of queue and make it (newNode) new tail
            trail->next = newNode;
            trail = newNode;
        }
}
// removes and returns the first item in the queue
int Queue::dequeue()
{
    if (isQueueEmpty())
        {
            return -1;
        }
        else
        {
            // Store the front node (head node) value in temp and move head to the next node
            int temp = head->data;
            Node* tempNode = head;
            head = head->next;
            
            // If head becomes NULL, then change tail also as NULL
            if (head == NULL)
                trail = NULL;
                
            delete tempNode; // deallocate memory for tempNode
            return temp;
        }
}
