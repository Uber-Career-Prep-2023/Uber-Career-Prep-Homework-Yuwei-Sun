//
//  AdjacencyList.cpp
//  Assignment-3
//
//  Created by user on 5/30/23.
//


// Assume the Graph is non directed
#include<iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Graph
class Graph {
    int V; // Vertices
    vector<int>* adjList; // Adjacent List
    vector<int> nodeValues; // Node values
    
public:
    Graph(int V); // Constructor
    
    void addEdge(int left, int right);
    
    void addNode(int value);
    
    void printAdjList();
    
    bool bfs(int target);
    
    bool dfsHelper(int current, int target, bool visited[]);
    
    bool dfs(int target);
    
    void topologicalSortHelper(int current, bool visited[], stack<int> &Stack);
    
    vector<int> topologicalSort();

};

Graph::Graph(int V){
    this->V = V;
    adjList = new vector<int>[V]; // create V adjList
}

// add Edge, assume non-directed
void Graph::addEdge(int left, int right){
    adjList[left].push_back(right);
    adjList[right].push_back(left);
}

// index -> value
void Graph::addNode(int value){
    nodeValues.push_back(value);
}

// print the AdjList with head
void Graph::printAdjList() {
    for (int i = 0; i < V; i++){
        cout << "Head " << i << ":";
        for (size_t j = 0; j < adjList[i].size(); j++){
            cout << " -> " << adjList[i][j];
        }
        cout << endl;
    }
}


bool Graph::bfs(int target){
    // initialize vector visited
    bool* visited = new bool[V];
    for (size_t i = 0; i < V; i++){
        visited[i] = false;
    }
    
    // push head into queue and mark it in visited
    queue<int> q;
    q.push(0); // start from first index, which is 0
    visited[0] = true;
    
    // take a node off from queue
    // if the node is target, then stop. If not, then visited all neighbors of this node (push into queue). And mark them as visitied
    // repeat untill queue is empty
    while (q.size() > 0) {
        int cursor = q.front(); // get element of head of queue, cursor of index
        q.pop(); // pop() function removes the first element of the queue
        
        if (nodeValues[cursor] == target) {
            return true;
        }
        else{
            for (size_t j = 0; j < adjList[cursor].size(); j++){
                if (!visited[j]) { // if it is not visited
                    q.push(adjList[cursor][j]); // put all unvisited neighbor nodes into the queue
                    visited[adjList[cursor][j]] = true; // mark as visited
            }
        }
        
        }
    }
    
    return false;
}

// Helper of dfs
bool Graph::dfsHelper(int current, int target, bool visited[]) {
    // mark start
    visited[current] = true;
    
    // found, return true
    if (current == target ){
        return true;
    }
    
    // Use iterator to access the whole branch where current is located
    for (auto i = adjList[current].begin(); i != adjList[current].end(); i++){ // Use auto, begin, end for iterator, which is more suitable for C++ STL
        
        // Recursion: 1. not visted. 2.dfsHelper will iterate all node untill found or all have been visited.
        // if found, if statement return true as result.
        if (!visited[*i]&&dfsHelper(*i, target, visited)){
            return true;
        }
    }
    return false;
}

// Search online for the recursive implement
// initialize visited
bool Graph::dfs(int target) {
    bool* visited = new bool[V];
    for (size_t i = 0; i < V; i++){
        visited[i] = false;
    }
    return dfsHelper(0, target, visited);
}

// Helper
void Graph::topologicalSortHelper(int current, bool visited[], stack<int> &Stack){
    visited[current] = true;
    // This recursive part is used to perform a DFS on each of the neighboring nodes. This ensures that all neighboring nodes of the current will be processed first when performing topological sorting.
    

    for (auto i = adjList[current].begin(); i != adjList[current].end(); i++){
        if (!visited[*i]){
            // pass in node(*i)
            topologicalSortHelper(*i, visited, Stack);
        }
    }
    // push the node into Stack, cuz it has already been processed
    Stack.push(current);
}

vector<int> Graph::topologicalSort(){
    stack<int> Stack;
    vector<int> Result;
    bool* visited = new bool[V];
    for (size_t i = 0; i < V; i++){
        visited[i] = false;
    }
    
    // Iterate over all vertices in the graph
    for (int i = 0; i < V; i++){
        if (!visited[i]){ // unvisited node
            topologicalSortHelper(i, visited, Stack);
        }
    }
    
    // get a node from stack, then insert it into vector
    while (!Stack.empty()){
        Result.insert(Result.begin(), Stack.top());//Stack's pop function does not return a value and needs to be used in conjunction with the top function.
        Stack.pop();
    }
    return Result;
}

 
int main(){
    // Graph Test
    Graph g(5);
    
    g.addNode(0);
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addNode(4);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printAdjList();
    
    cout << g.dfs(6) << endl;
    cout << g.bfs(4) << endl;
    
    vector<int> tp = g.topologicalSort();
    for (int i = 0; i < tp.size(); i++){
        cout << tp[i];
        cout << " ";
    }
    
}
