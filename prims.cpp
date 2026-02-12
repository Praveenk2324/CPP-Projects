//Prims
#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int primsMST(int V, vector<vector<pair<int, int>>>& adj){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    int mstWeight = 0;
    vector<bool> visited(V, false);
    pq.push({0,0});

    cout << "Edges in MST:\n";

    while(!pq.empty()){
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(visited[u]) continue;

        visited[u] = true;

        visited[u] = true;
        mstWeight += weight;

        for(auto& edge : adj[u]){
            int v = edge.first;
            int w = edge.second;

            if(!visited[v]){
                pq.push({w, v});
            }
        }
    }
    return mstWeight;
}

int main(){
    int V = 5;

    vector<vector<pair<int, int>>> adj(V);

    auto addEdge = [&](int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    int totalWeight = primsMST(V, adj);
    
    cout << "Total weight of Minimum Spanning Tree: " << totalWeight << endl;
    return 0;
}
