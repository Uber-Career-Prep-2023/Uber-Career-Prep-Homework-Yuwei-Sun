//
//  main.cpp
//  Data Structure Implementations
//
//  Created by user on 4/6/23.
//

#include <iostream>

#include "DoublyLinkedList.cpp"
#include "SinglyLinkedList.h"
#include "BST.hpp"
#include "Queue.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, HW2!\n";
    
    SinglyLinkedList* mySLL = new SinglyLinkedList();
    mySLL->insertAtBack(1);
    mySLL->insertAtBack(2);
    mySLL->insertAtBack(3);
    mySLL->insertAtBack(4);
    mySLL->listDisplay();
    mySLL->reverseIterative();
    mySLL->listDisplay();

    // namespace
    DoublyLinkedList::DoublyLinkedList* myDLL = new DoublyLinkedList::DoublyLinkedList();
    myDLL->insertAtBack(1);
    myDLL->insertAtBack(2);
    myDLL->insertAtBack(3);
    myDLL->insertAtBack(4);
    myDLL->listDisplay();
    myDLL->reverseIterative();
    myDLL->listDisplay();
    
    BST bst = *new BST();

    // Inserting values into BST
    bst.insert(15);
    bst.insert(10);
    bst.insert(20);
    bst.insert(8);
    bst.insert(12);
    bst.insert(17);
    bst.insert(25);

    cout << "Min value: " << bst.min() << endl;
    cout << "Max value: " << bst.max() << endl;  
    
    cout << bst.contains(11) << endl;
    
    // deleteVal wrong
    
    
    Queue* queue = new Queue();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    cout << queue->isQueueEmpty() << endl;
    
    int temp = queue->dequeue();
    cout << temp << endl;
    
    cout << queue->peek() << endl;
    
    
    return 0;
}

