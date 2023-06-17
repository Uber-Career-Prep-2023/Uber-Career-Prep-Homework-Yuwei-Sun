//
//  PriorityQueue.cpp
//  Assignment-3
//
//  Created by user on 5/31/23.
//

// Implement by Heap
// The min key have is the prioritiest item

// Assume the value is immutable, and priority can be 0 and negative number

#include<vector>
#include <iostream>
#include <string>
using namespace std;

struct Item{
    int priority;
    string value;
    
    // constructer
    Item(int p, const string& val):priority(p), value(val) {}
    
    // comparison overload
    friend bool operator < (const Item& l, const Item& r)
        {
        return l.priority < r.priority;
        }
    friend bool operator > (const Item& l, const Item& r)
        {
        return r < l;
        }
    friend bool operator <= (const Item& l, const Item& r)
        {
        return !(l > r);
        }
    friend bool operator >= (const Item& l, const Item& r)
        {
        return !(l < r);
        }
    friend bool operator == (const Item& l, const Item& r)
        {
        return l.priority == r.priority;
        }
    friend bool operator != (const Item& l, const Item& r)
        {
        return !(l==r);
        }
    
};

class PriorityQueue{
    vector<Item> data; // vecter can store Item
    
    // parent, left, right
    size_t parent(size_t i) const {
        return (i-1)/2;
    }
    size_t left(size_t i) const {
        return 2*i+1;
    }
    size_t right(size_t i) const {
        return 2*i+2;
    }
    
    // bubble-up, bubble-down
    void bubbleUp(size_t i){
        if (data[parent(i)] > data[i]){
            Item temp = data[i];
            data[i] = data[parent(i)];
            data[parent(i)] = temp;
            bubbleUp(parent(i)); // recursivly up
        }
    }
    
    void bubbledown(size_t i){
        size_t min = i;
        size_t l = left(i);
        size_t r = right(i);
        
        if (l < data.size() && data[l] < data[i] ){
            min = l;
        }
        if (r < data.size() && data[r] < data[min]){
            min = r;
        }
        if (min != i){
            Item temp = data[i];
            data[i] = data[min];
            data[min] = temp;
            bubbledown(min);
        }
    }
    
public:
    size_t size() const{
        return data.size();
    }
    
    bool isEmpty() const{
        return data.empty();
    }
    
    void insert(int p, const string& val){
        Item newItem = Item(p,val);
        data.push_back(newItem);
        bubbleUp(size()-1);
    }
    
    void remove(){
        if (isEmpty()){
            cout << "Empty!" << endl;
        }
        data[0] = data.back(); // move last one to top(top has been remove)
        data.pop_back(); //remove last one
        bubbledown(0);
    }
    
    const string& top() const {
        if (data.size() == 0){
            Item noneItem = Item(INT_MAX,"Nothing");
            return noneItem.value; // same as Heap
            // Or throw error maybe
            
        }
        else {
            return data[0].value;
        }
    }
    
    
};

/*
int main(){
    PriorityQueue PQ;
    
    PQ.insert(3,"C");
    PQ.insert(5,"E");
    PQ.insert(1,"A");
    PQ.insert(2,"B");
    PQ.insert(4,"D");
    
    cout << PQ.top() << endl;
    PQ.remove();
    cout << PQ.top() << endl;
    
}
*/
