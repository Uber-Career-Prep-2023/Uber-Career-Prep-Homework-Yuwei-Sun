//
//  Heap.cpp
//  Assignment-3
//
//  Created by user on 5/30/23.
//

// Implement by binary tree

#include <vector>
#include <iostream>
using namespace std;

class minHeap{
    vector<int> data;
    
    // parent, left, right
    size_t parent(size_t i) const{
        return (i-1)/2;
    }
    size_t left(size_t i) const{
        return 2*i+1;
    }
    size_t right(size_t i) const{
        return 2*i+2;
    }
    
    // bubble-up, bubble-down
    void bubbleUp(size_t i){
        if (data[parent(i)] > data[i]){
            int temp = data[i];
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
        if (r<data.size() && data[r] < data[min]){
            min = r;
        }
        if (min != i){
            int temp = data[i];
            data[i] = data[min];
            data[min] = temp;
            bubbledown(min);
        }
    }
public:
    void insert(int key) {
          data.push_back(key);
          size_t index = data.size() - 1;
        bubbleUp(index);
      }
        
    // put last into top, and then remove last element
      void remove() {
          if (data.size() == 0){
              cout << "empty" << endl;
          }
          else {
              data[0] = data.back();
              data.pop_back();
              bubbledown(0);
          }
      }
    
      int top() const {
          if (data.size() == 0){
              cout << "empty" << endl;
              return INT_MIN; // search on google, min value for INT type
          }
          else {
              return data[0];
          }
      }
    
};

/*
int main(){
    minHeap heap;
    
    heap.insert(3);
    heap.insert(5);
    heap.insert(1);
    heap.insert(2);
    heap.insert(4);
    
    cout << heap.top() << endl;
    heap.remove();
    cout << heap.top() << endl;
    
}
*/
