//
//  BST.hpp
//  Data Structure Implementations
//
//  Created by user on 4/8/23.
//  g++ main.cpp BST.cpp -o my_program
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>

#include <iostream>
using namespace std;

class BST
{
public:
    //returns the min/max value in the BST
    int min();
    int max();
    
    //returns a boolean indicating whether val is present in the BST
    bool contains(int val);
    
    //creates a new Node with data val in the appropriate location
    void insert(int val);
    
    //deletes the Node with data val, if it exists
    int deleteVal(int val);
    
private:
    struct Node
    {
        int val;
        Node* left;
        Node* right;
        // constructor
        Node(int val): val(val),left(nullptr),right(nullptr){}
    };
    
    Node* root;
    // left traverse
    Node* findMin(Node* node);
    // return the root. insertion/delete may change the root
    Node* insert(Node* node, int val);
    Node* deleteVal(Node* node, int val);
};
#endif /* BST_hpp */
