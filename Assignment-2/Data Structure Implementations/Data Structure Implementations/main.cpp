//
//  main.cpp
//  Data Structure Implementations
//
//  Created by user on 4/6/23.
//

#include <iostream>

#include "DoublyLinkedList.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, HW2!\n";
    Node* head = new Node(1);
    head->next = new Node(2);
    listDisplay(head);
    return 0;
}

