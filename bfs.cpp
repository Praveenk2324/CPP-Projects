#include<iostream>
#include<vector>
#include<queue>


using namespace std;

void bfs(int startNode, const vector<vector<int>>& adjList){
    int numNodes = adjList.size();

    vector<bool> visited(numNodes, false);

    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout<< "BFS Traversal: ";

    while(!q.empty()){
        int currentNode = q.front();
        q.pop();

        cout << currentNode << " ";
        
        for(int neighbor : adjList[currentNode]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
    int main() {
    // Number of vertices in the graph
    int numNodes = 6;

    // Representing the graph using an adjacency list
    vector<vector<int>> adjList(numNodes);

    // Adding edges (Undirected graph)
    // Graph looks like:
    //      0
    //     / \
    //    1   2
    //   / \   \
    //  3   4   5
    
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 5};
    adjList[3] = {1};
    adjList[4] = {1};
    adjList[5] = {2};

    // Perform BFS starting from node 0
    bfs(0, adjList);

    return 0;
}