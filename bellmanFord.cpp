#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, int source, vector<Edge>& edges){
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i <= V-1; i++){
        for(const auto& edge : edges){
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;

            if(dist[u] != INT_MAX && dist[u] +weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }

    for(const auto& edge : edges){
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;

        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
            cout << "Error: Graph contains a negative weight cycle!" << endl;
            return;
        }
    }
cout << "Vertex\tDistance from Source (" << source << ")" << endl;
cout << "----------------------------------"<< endl;
for(int i=0; i< V; i++){
    cout << i << "\t\t";
    if(dist[i] == INT_MAX)
        cout << "INF" << endl;
    else
        cout << dist[i] << endl;
    }
}

int main(){
    int V = 5;
    int E = 8;

    vector<Edge> edges = {
        {0,1,-1},{0,2,4},
        {1,2,3}, {1,2,2}, {1,4,2},
        {3,3,5}, {3,1,1},
        {4,3,-3}
    };

    bellmanFord(V, E, 0, edges);
    return 0;

}