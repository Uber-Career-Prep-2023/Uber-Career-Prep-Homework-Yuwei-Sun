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
    bool isEmpty() const;
    // returns the first item in the queue
    int peek() const;
    // adds x to the back of the queue
    void enqueue(int x);
    // removes and returns the first item in the queue
    int dequeue() const;
    
    
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
bool Queue::isEmpty() const
{
    return head==nullptr;
}

// returns the first item in the queue
int Queue::peek() const
{
    // empty queue
    if (isEmpty())
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
    
}
// removes and returns the first item in the queue
int Queue::dequeue() const
{
    return -1;
}
