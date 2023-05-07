//
//  main.cpp
//  Data Structure Implementations
//
//  Created by user on 4/6/23.
//

#include <iostream>

#include "DoublyLinkedList.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, HW2!\n";

    
    DoublyLinkedList::DoublyLinkedList* myDLL = new DoublyLinkedList::DoublyLinkedList();
    myDLL->insertAtBack(1);
    myDLL->insertAtBack(2);
    myDLL->insertAtBack(3);
    myDLL->insertAtBack(4);
    myDLL->listDisplay();
    myDLL->reverseIterative();
    myDLL->listDisplay();
    return 0;
}

