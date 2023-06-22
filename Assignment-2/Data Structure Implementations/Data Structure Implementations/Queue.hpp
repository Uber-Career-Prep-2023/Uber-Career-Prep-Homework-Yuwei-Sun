//
//  Queue.hpp
//  Data Structure Implementations
//
//  Created by user on 4/9/23.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

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

#endif /* Queue_hpp */
