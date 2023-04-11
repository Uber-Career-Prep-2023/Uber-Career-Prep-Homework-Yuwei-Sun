//
//  BST.cpp
//  Data Structure Implementations
//
//  Created by user on 4/8/23.
//

#include "BST.hpp"

// returns the minimum value in the BST
int BST::min()
{
    if (root == nullptr)
    {
        throw "Empty tree";
    }
    
    Node* cursor = root;
    while (cursor->left != nullptr)
    {
        cursor = cursor->left;
    }
    
    return cursor->val;
}

// returns the maximum value in the BST
int BST::max()
{
    if (root == nullptr)
    {
        throw "Empty tree";
    }
    
    Node* cursor = root;
    while (cursor->right != nullptr)
    {
        cursor = cursor->right;
    }
    
    return cursor->val;
}

//returns a boolean indicating whether val is present in the BST
bool BST::contains(int val)
{
    Node* cursor = root;
    while (cursor != nullptr)
    {
        // find
        if (cursor->val == val)
        {
            return true;
        }
        // search on the left
        else if (cursor->val < val)
        {
            cursor = cursor->left;
        }
        // search on the right
        else
        {
            cursor = cursor->right;
        }
    }
    return false;
}

// insert a value to BST, and return new root
BST::Node* BST::insert(Node* node,int val)
{
    // insert at the first node
    if (node == nullptr)
    {
        return new Node(val);
    }
    // left call
    else if (node->val > val)
    {
        node->left = insert(node->left, val);
    }
    // right call
    else
    {
        node->right = insert(node->right, val);
    }
    return node;
}

// creates a new Node with data val in the appropriate location
void BST::insert(int val)
{
    root = insert(root,val);
}

// delete certain value in BST, and return new root
BST::Node* BST::deleteVal(Node* node, int val)
{
    return node;
}

