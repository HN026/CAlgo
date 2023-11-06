#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

// Dijkstras Algorithms cannot be applied to graphs with negative weights as it will fall into infinite loop.
// Time complexity of Djikstras Algorithm is O(ElogV) where E is the number of edges and V is the number of vertices.

using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int v, int source){
    vector<pair<int,int>> adj[v];
    for(size_t i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Priority queue -> min heap
    vector<int> dist(v, INT_MAX);
    dist[source] = 0;
    pq.push({0, source}); // distance and node 

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto adjNode: adj[node]){
            int nd = adjNode.first;
            int weight = adjNode.second;
            if(distance + weight < dist[nd]){
                dist[nd] = distance + weight;
                pq.push({dist[nd], nd});
            }
        }
    }
    return dist;
}

int main(){

    int v = 4;
    vector<vector<int>> edges = {
        {0,1,5},
        {0,2,8},
        {1,2,9},
        {1,3,2},
        {2,3,6}
    };
    vector<int> ans = dijkstra(edges, v, 0);

    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}