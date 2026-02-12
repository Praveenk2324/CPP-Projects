//Dijkstra
#include<iostream>
#include<vector>
#include<queue>
#include<limits>

using namespace std;

const int INF = numeric_limits<int>::max();

typedef pair<int, int> pii;

void dijkstra(int startNode, int n, const vector<vector<pii>>& adj) {
    vector<int> dist(n, INF);
    dist[startNode] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, startNode});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if(d > dist[u]) continue;

        for(auto& edge : adj[u]){
            int v = edge.first;
            int weight = edge.second;

            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << startNode << ":\n";
    for(int i = 0; i < n; i++){
        if(dist[i] == INF)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main(){
    int n = 5;
    vector<vector<pii>> adj(n);

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    dijkstra(0, n, adj);

    return 0;

}