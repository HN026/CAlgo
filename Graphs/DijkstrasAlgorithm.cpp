#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

// Dijkstras Algorithms cannot be applied to graphs with negative weights as it will fall into infinite loop.
// Time complexity of Djikstras Algorithm is O(ElogV) where E is the number of edges and V is the number of vertices.

using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int v, int source){
    vector<vector<int>> adj[4];
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> dist(v, 1e9);
    dist[source] = 0;
    q.push({0, source});

    while(!q.empty()){
        int adjNode = q.top().second;
        int weight = q.top().first;
        q.pop();

        for(auto neighNodes: adj[adjNode]){

            int node = neighNodes[0];
            int wt = neighNodes[1];

            if(weight + wt < dist[node]){
                dist[node] = wt + weight;
                q.push({dist[node], node});
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